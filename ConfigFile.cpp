#include "DataMemory.h"
#include "math.h"
#include "ConfigFile.h"
#include <iostream>
#include <vector>

ConfigFile::ConfigFile() { }

ConfigFile::ConfigFile(string const& s1,string const& s2, string const& s3, string const& s4, bool const& b1, bool const& b2, bool const& b3,string const& s5){

 	myProgramInput=s1;
	myMemoryInput=s2;
 	myRegisterInput=s3;
 	myOutputMode=s4;
	myDebugMode=b1;
	myPrintMemContent=b2;
	myWriteToFile=b3;
	myOutputFile=s5;
}


