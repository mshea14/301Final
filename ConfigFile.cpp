#include "DataMemory.h"
#include "math.h"
#include <iostream>
#include <vector>

ConfigFile::ConfigFile(string s1,string s2, string s3, string s4, bool b1, bool b2, bool b3,string s5){

 	myProgramInput=s1;
	myMemoryInput=s2;
 	myRegisterInput=s3;
 	myOutputMode=s4;
	myDebugMode=b1;
	myPrintMemContent=b2;
	myWriteToFile=b3;
	myOutputFile=s5;
}


