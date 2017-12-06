#include "data.h"
#include "ConfigFile.h"
#include "Operation.h"
#include "Multiplexor.h"
#include "DataMemory.h"
#include "ALU.h"
#include "ASMParser.h"
#include "ConfigFile.h"
#include "Instruction.h"
#include "RegisterFile.h"
#include "PCounter.h"
#include <iostream> 


void fetch(Instruction i);
void decode(Instruction i);
void execute(Instruction i);
void writback(Instruction i);
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
ConfigFile configFile;
DataMemory dataMem;

string currentAddress;

//create new operation
Operation o;

//create new parser
Parser p;

string opcode;
string rs;
string rt;
string rd;
string immediate;
string jumpAmount;
PCounter programCounter = new PCounter();

int main(int argc, const char * argv[]) {
	
	//validate input 
	if(argc < 2){
    cerr << "Need to specify a config file to translate."<<endl;
    exit(1);
  	}

  	
  	//create config file
	configFile = p.parseConfigFile(argv[2]);

	//create register file
	registerFile = p.parseRegister(configFile.myRegisterInput);

	//create Data Memory
	dataMem = p.parseMemory(configFile.myMemoryInput);

	//create new parser
	asmParse = new ASMParser(configFile.myProgramInput);



	 if(parser->isFormatCorrect() == false){
	    cerr << "Format of input file is incorrect " << endl;
	    exit(1);
	 }


	 //counter 
	 int j=0;

	//Iterate through instructions, printing each encoding.
  	i = parser->getNextInstruction();
  	while( i.getOpcode() != UNDEFINED){
    
	

	    //print out instruction being executed
		p.readAndPrintInstruction(j, configFile.myProgramInput);


		fetch(i);
		decode(i);
		execute(i);
		memory(i);
		writeback(i);
	  

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
	programCounter.setAdress(aluAdd.getOutput());
	    
	    
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


	opcode = getOpcodeField(i.getOpcode());

}

void decode(Instruction i)
{
	//get control values 
	INS controlLines = i.getControlValues();

	//print control lines
	i.printControlValues();

	//send signals 

	//REG DST
	if(configFile.myDebugMode) cout << "Setting Multiplexor 1" << endl;
	if(!controlLines.RegDest.equals("X")) cout << "RegDest not used" << endl;
	else 
	{
		registerMux.setControl(controlLines.RegDest);
	}
	


	//JUMP
	if(configFile.myDebugMode) cout << "Setting Jump Line" << endl;
	if(!controlLines.Jump.equals("X")) cout << "Jump not used" << endl;
	else 
	{
		jumpOrAddMux.setControl(controlLines.Jump);
	}

	//BRANCH
	if(configFile.myDebugMode) cout << "Setting Branch Line" << endl;
	if(!controlLines.Branch.equals("X")) cout << "Branch not used" << endl;
	else 
	{
		string controlForBranch;

		if(controlLines.Branch=='1' && aluALUandResult.getComparedResult()) branchOrAddMux.setControl("1");
		else branchOrAddMux.setControl("0");

	}


	//REG DST
	if(configFile.myDebugMode) cout << "Setting Multiplexor 1" << endl;
	if(!controlLines.MemtoReg.equals("X")) cout << "MemToReg not used" << endl;
	else
	{
		rmemOrALUMux.setControl(controlLines.MemtoReg);
	}

	



	




}
void execute(Instruction i)
{


}
void memory(Instruction i)
{

}

void writeback(Instruction i)
{

}






