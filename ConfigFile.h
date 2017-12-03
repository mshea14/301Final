using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

   

class ConfigFile{
 	public:

  	ConfigFile(string s1,string s2, string s3, string s4, bool b1, bool b2, bool b3,string s5);

	string myProgramInput;
	string myMemoryInput;
	string myRegisterInput;
	string myOutputMode;
	bool myDebugMode;
	bool myPrintMemContent;
	bool myWriteToFile;
	string myOutputFile;

};