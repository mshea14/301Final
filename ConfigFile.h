#ifndef Config_h
#define Config_h

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

   

class ConfigFile{
 	public:
    
    ConfigFile();
  	ConfigFile(string const& s1,string const& s2, string const& s3, string const& s4, bool const& b1, bool const& b2, bool const& b3,string const& s5);

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
