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


	//Iterate through instructions, printing each encoding.
	i = parser->getNextInstruction();
	while( i.getOpcode() != UNDEFINED){
	   


		i = parser->getNextInstruction();
	}

	while(true)
	{
		 //first print out memory and register
		if(configFile.myPrintMemContent)  
		{
			dataMem.printDataMemory();
			registerFile.printRegisterFile();

		}	

	    //print out instruction being executed
		if(configFile.myDebugMode) 
		{
			//print out current instruction
		}

	
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


   	
		//mux/ALU


		//fetching instruction
	    if(configFile.myDebugMode) 
		{
			cout << "Incrementing PC" << endl;
		}

		aluAdd.setOperand1(programCounter.getAddress());
		aluAdd.setOperand2("4");
		aluAdd.add(programCounter.getAddress(), "4");
	   	programCounter.setAdress(aluAdd.getOutput());
	    
	    


		Opcode o = i.getOpcode();
		//RTYPE
		if(o==000000)
		{
			if(getFunctField(o)==100000)
			{

			}
		}




	 
		//Update memory/register 


		//if print memory contents is true, print out memory, register files
		if(configFile.myPrintMemContent)  
		{
			dataMem.printDataMemory();
			registerFile.printRegisterFile();

		}	

	}




	return 0;


}
