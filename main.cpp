
#include "ConfigFile.h"
#include "Operation.h"
#include "Multiplexor.h"
#include "ALU.h"
#include "ASMParser.h"
#include "Instruction.h"
#include "PCounter.h"
#include "Parser.h"
#include "Opcode.h"
#include <iostream> 
#include <string>
#include <stdlib.h>
#include <numeric>
using namespace std;

void fetch(Instruction i);
void decode(Instruction i);
void execute(Instruction i);
void memory(Instruction i);

ALU aluAdd; //ALU 1
ALU aluAddandResult; //ALU 2
ALU aluALUandResult; //ALU 3
Multiplexor registerMux;  //Mux
Multiplexor registerOrImmMux;  //Mux
Multiplexor memOrALUMux; //Mux
Multiplexor branchOrAddMux; //Mux
Multiplexor jumpOrAddMux; //Mux
RegisterFile registerFile;
DataMemory dataMem;
ConfigFile configFile;
string currentAddress;


//create new operation
Operation o;

//create new parser
Parser p;

//instruction 
Instruction i;

//opcode 
OpcodeTable op;

string opcode;
string rs;
string rt;
string rd;
string immediate;
string functionField;
string jumpAmount;
PCounter programCounter= PCounter();

int main(int argc, const char * argv[]) {
	
	//validate input 
	if(argc < 2){
    cerr << "Need to specify a config file to translate."<<endl;
    exit(1);
  	}
	cout << argv[1] << endl;

  	cout << "Valid File" << endl;
  	//create config file
	 configFile= p.parseConfigFile(argv[1]);
	 cout << "Found config file" << endl;

	//create register file
	registerFile = p.parseRegister(configFile.myRegisterInput);

	//create Data Memory
	dataMem = p.parseMemory(configFile.myMemoryInput);

	//create new parser
	ASMParser asmParse = ASMParser(configFile.myProgramInput);



	 if(asmParse.isFormatCorrect() == false){
	    cerr << "Format of input file is incorrect " << endl;
	    exit(1);
	 }
	 

	 //counter 
	 int j=0;

	//Iterate through instructions, printing each encoding.
  	i = asmParse.getNextInstruction();
  	while( i.getOpcode() != UNDEFINED){
    
	

	    //print out instruction being executed
		p.readAndPrintInstruction(j, configFile.myProgramInput);


		fetch(i);
		decode(i);
		execute(i);
		memory(i);
	  

		//if print memory contents is true, print out memory, register files
		if(configFile.myPrintMemContent)  
		{
			dataMem.printDataMemory();
			registerFile.printRegisterFile();
			//print out instruction memory

		}

		//increment up register file 
		j++;

  	}
  


	//SET IF DEBUG OR WRITE TO FILE
	o.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	aluAdd.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile); 
	aluAddandResult.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	aluALUandResult.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile); 
	registerMux.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile); 
	registerOrImmMux.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	memOrALUMux.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	branchOrAddMux.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	jumpOrAddMux.SetDebugAndFile(configFile.myDebugMode, configFile.myWriteToFile);
	

       	return 0;
	 

}

void fetch(Instruction i)
{
	if(configFile.myDebugMode) 
	{
		cout << "Incrementing PC" << endl;
	}
	currentAddress =programCounter.getAddress();
	aluAdd.setOperand1(currentAddress);
	aluAdd.setOperand2("00000000000000000000000000000100");
	aluAdd.add(currentAddress, "00000000000000000000000000000100");
	programCounter.setAddress(aluAdd.getOutput());
	    
	    
	if(configFile.myDebugMode) 
	{
		cout << "Input to Multiplexor 5 Operand 0 set" << endl;
	}
	branchOrAddMux.setInputZero(currentAddress);


	if(configFile.myDebugMode) 
	{
		cout << "Input to ALU Add and Result Operand 0 set" << endl;
	}
	aluAddandResult.setOperand1(currentAddress);


	opcode = op.getOpcodeField(i.getOpcode());

}

void decode(Instruction i)
{
	//get control values 
	Instruction::INS controlLines = i.getControlValues();

	//print control lines
	i.printControlValues();

	//send signals 

	//REG DST
	if(configFile.myDebugMode) cout << "Setting Multiplexor 1" << endl;
	if(controlLines.RegDst.compare("X")!=0) cout << "RegDest not used" << endl;
	else 
	{
		registerMux.setControl(controlLines.RegDst);
	}
	


	//JUMP
	if(configFile.myDebugMode) cout << "Setting Jump Line" << endl;
	if(controlLines.Jump.compare("X")!=0) cout << "Jump not used" << endl;
	else 
	{
		jumpOrAddMux.setControl(controlLines.Jump);
	}

	//BRANCH
	if(configFile.myDebugMode) cout << "Setting Branch Line" << endl;
	if(controlLines.Branch.compare("X")!=0) cout << "Branch not used" << endl;
	else 
	{
		string controlForBranch;

		if(controlLines.Branch.compare("1")==0 && aluALUandResult.getComparedResult()) branchOrAddMux.setControl("1");
		else branchOrAddMux.setControl("0");

	}


	//MemtoReg
	if(configFile.myDebugMode) cout << "Setting Multiplexor 3" << endl;
	if(controlLines.MemtoReg.compare("X")!=0) cout << "MemToReg not used" << endl;
	else
	{
		memOrALUMux.setControl(controlLines.MemtoReg);
	}



	//ALU SRC
	if(configFile.myDebugMode) cout << "Setting Multiplexor 2" << endl;
	if(controlLines.ALUSrc.compare("X")==0) cout << "ALUSrc not used" << endl;
	else
	{
		registerOrImmMux.setControl(controlLines.ALUSrc);
	}



}
void execute(Instruction i)

{

	if(i.getControlValues().RegDst != "X"){
		registerMux.setInputOne(to_string((int)i.getRD()));
		registerMux.setInputZero(to_string((int)i.getRT()));
	} 
	registerMux.execute();

	registerOrImmMux.setInputOne(o.SignExtend(o.HexToBinary(o.IntToHex(i.getImmediate()))));
	registerOrImmMux.setInputZero(to_string((int)i.getRT()));

	registerOrImmMux.execute();

	aluALUandResult.setOperand1(registerOrImmMux.getOutput());
	aluALUandResult.setOperand2(to_string((int)i.getRS()));

	//set operation
	//r-type 
	if(opcode.compare("000000")==0)
	{

		functionField = op.getFunctField(i.getOpcode());
		if(functionField.compare("100000")==0) aluAddandResult.runALU("add");
		if(functionField.compare("100010")==0) aluAddandResult.runALU("subtract");
		if(functionField.compare("101010")==0) aluAddandResult.runALU("less");

	}
	else if(opcode.compare("000100")==0)
	{
		aluAddandResult.runALU("equal");
	}
	


	if(i.getControlValues().MemtoReg != "X"){
		memOrALUMux.setInputOne(dataMem.getData(aluALUandResult.getOutput()));
		memOrALUMux.setInputZero(aluALUandResult.getOutput());
		memOrALUMux.execute();
	} 

	aluAddandResult.setOperand1(o.ShiftLeftTwo(o.SignExtend(o.HexToBinary(o.IntToHex(i.getImmediate())))));
	aluAddandResult.setOperand2(programCounter.getAddress());
	aluAddandResult.runALU("add");


	//branch 
	branchOrAddMux.setInputOne(aluAddandResult.getOutput());
	branchOrAddMux.setInputZero(programCounter.getAddress());
	branchOrAddMux.execute();


	//jump
	jumpOrAddMux.setInputOne(programCounter.getAddress().substr(0,4)+o.ShiftLeftTwo(o.SignExtend(o.HexToBinary(o.IntToHex(i.getImmediate())))));
	jumpOrAddMux.setInputZero(branchOrAddMux.getOutput());
	jumpOrAddMux.execute();
	programCounter.setAddress(jumpOrAddMux.getOutput());


	


}
void memory(Instruction i)
{
	if (i.getControlValues().MemWrite == "1")
	{

		dataMem.setMemory(aluALUandResult.getOutput(), registerFile.getRegister((int)i.getRS()));
	}
	if(i.getControlValues().MemRead == "1")
	{
		registerFile.setRegister((int)i.getRS(), dataMem.getData(aluALUandResult.getOutput()));
	}

}







