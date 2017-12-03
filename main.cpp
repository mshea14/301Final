#include <data.h>
#include <ConfigFile.h>
#include <iostream> 

int main(int argc, const char * argv[]) {
	
	//need to keep track of what instruction we are parsing
	if(argc < 2){
    cerr << "Need to specify a config file to translate."<<endl;
    exit(1);
  	}

  
	ConfigFile configFile = parseConfigFile(argv[2]);
	RegisterFile registerFile = parseRegister(configFile.myRegisterInput);
	DataMemory dataMem = parseMemory(configFile.myMemoryInput);

	cout << "Print memory contents set to: " << configFile.myPrintMemContent << endl;

	parser = new ASMParser(configFile.myProgramInput);

	 if(parser->isFormatCorrect() == false){
	    cerr << "Format of input file is incorrect " << endl;
	    exit(1);
	 }

	  Instruction i;

	  //Iterate through instructions, printing each encoding.
	  i = parser->getNextInstruction();
	  while( i.getOpcode() != UNDEFINED){
	    
	  








	    i = parser->getNextInstruction();
	  }





	return 0;


}
