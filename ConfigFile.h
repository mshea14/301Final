#ifndef Config_h
#define Config_h


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

   

class ConfigFile{
 	public:
    ConfigFile(string const& s1,string const& s2, string const& s3, string const& s4, bool const& b1, bool const& b2, bool const& b3,string const& s5);
    ConfigFile();

	string myProgramInput;
	string myMemoryInput;
	string myRegisterInput;
	string myOutputMode;
	bool myDebugMode;
	bool myPrintMemContent;
	bool myWriteToFile;
	string myOutputFile;

};
#endif
