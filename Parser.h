#ifndef Parser_h
#define Parser_h

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "RegisterFile.h"
#include "DataMemory.h"
#include "ConfigFile.h"
#include <string>
#include <cstring>
using namespace std;

class Parser{

	public:
    
	Parser();
    
    void readAndPrintInstruction(int i, string filename);
    
	ConfigFile parseConfigFile(string filename);

	RegisterFile parseRegister(string filename);

	DataMemory parseMemory(string filename);

};
#endif
