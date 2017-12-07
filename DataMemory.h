#ifndef DataMemory_h
#define DataMemory_h



#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <map>
using namespace std;

   

class DataMemory{
 	public:

  	DataMemory();

  	void addToMemory(string s1,string s2);

 	string getData(string i);

  	void setMemory(string s1, string s2);

  	void printDataMemory(string filename);
    void printDataMemoryToTerminal(string filename);

	protected:

	map<string,string> myContents;
};
#endif
