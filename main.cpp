#include <data.h>
#include "ConfigFile.h"
#include "Operation.h"
#include "Multipexlor.h"
#include "DataMemory.h"
#include "ALU.h"
#include "ASMParser.h"
#include "CongfigFile.h"
#include "Instruction.h"
#include "RegisterFile.h"
#include "PCounter.h"
#include <iostream> 


void fetch(Instruction i);
void decode(Instruction i);
void execute(Instruction i);
void writback(Instruction i);
void memory(Instruction i);


int main(int argc, const char * argv[]) {
	
	//validate input 
	if(argc < 2){
    cerr << "Need to specify a config file to translate."<<endl;
    exit(1);
  	}

  	
  	//create config file
	ConfigFile configFile = parseConfigFile(argv[2]);

	//create register file
	RegisterFile registerFile = parseRegister(configFile.myRegisterInput);

	//create Data Memory
	DataMemory dataMem = parseMemory(configFile.myMemoryInput);

	//create new parser
	parser = new ASMParser(configFile.myProgramInput);

	//create new operation
	Operation o;



	ALU aluAdd; //ALU 1
	ALU aluAddandResult; //ALU 2
	ALU aluALUandResult; //ALU 3
	Multiplexor registerMux;  //Mux
	Multiplexor registerOrImmMux;  //Mux
	Multiplexor memOrALUMux; //Mux
	Multiplexor branchOrAddMux; //Mux
	Multiplexor jumpOrAddMux; //Mux


	string opcode;
	string rs;
	string rt;
	string rd;
	string immediate;
	string jumpAmount;


	 if(parser->isFormatCorrect() == false){
	    cerr << "Format of input file is incorrect " << endl;
	    exit(1);
	 }

	cout << "Print memory contents set to: " << configFile.myPrintMemContent << endl;
	
	Instruction i;
	PCounter programCounter = new PCounter();


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


	

	while(true)
	{	
		//GET CURRENT INSTRUCTION!
		public Instruction i;

		 //first print out memory and register
		if(configFile.myPrintMemContent)  
		{
			dataMem.printDataMemory();
			registerFile.printRegisterFile();
			//PRINT OUT ALL INSTRUCTIONS

		}	

	    //print out instruction being executed
		if(configFile.myDebugMode) 
		{
			//print out current instruction
		}

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

		}	

	}




	return 0;


}

void fetch(Instruction i)
{
	if(configFile.myDebugMode) 
	{
		cout << "Incrementing PC" << endl;
	}

	aluAdd.setOperand1(programCounter.getAddress());
	aluAdd.setOperand2("00000000000000000000000000000100");
	aluAdd.add(programCounter.getAddress(), "00000000000000000000000000000100");
	programCounter.setAdress(aluAdd.getOutput());
	    
	    
	if(configFile.myDebugMode) 
	{
		cout << "Input to Multiplexor 5 Operand 0 set" << endl;
	}
	branchOrAddMux.setInputZero(programCounter.getAddress());


	if(configFile.myDebugMode) 
	{
		cout << "Input to ALU Add and Result Operand 0 set" << endl;
	}
	aluAddandResult.setOperand1(programCounter.getAddress());

	opcode = i.getOpcode();
	rs = i.getRs();
	rt = i.getRt();
	rd = i.getRd();
	immediate = i.getImmediate();
	jumpAmount = i.getJumpAmount();

}

void decode(Instruction i)
{
	//get control values 
	INS controlLines = i.getControlValues();
	cout <<  "Control Line - RegDst: 0x" << controlLines.RegDest << endl;
	cout <<  "Control Line - ALUSrc: 0x" << controlLines.ALUSrc << endl;
	cout <<  "Control Line - MemToReg: 0x" << controlLines.MemtoReg << endl;
	cout <<  "Control Line - RegWrite: 0x" << controlLines.Regwrite << endl;
	cout <<  "Control Line - MemRead: 0x" << controlLines.MemRead << endl;
	cout <<  "Control Line - MemWrite: 0x" << controlLines.MemWrite << endl;
	cout <<  "Control Line - Branch: 0x" << controlLines.Branch << endl;
	cout <<  "Control Line - ALUOp1: 0x" << controlLines.ALUOp1 << endl;
	cout <<  "Control Line - ALUOp0: 0x" <<controlLines.ALUOp0 << endl;
	cout << "Control Line - Jump: 0x" <<controlLines.ALUOp0 << endl;	
	

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






