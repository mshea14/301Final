#ifndef DataMemory_h
#define DataMemory_h

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <map>

   

class DataMemory{
 	public:

  	DataMemory();

  	void addToMemory(string s1,string s2);

 	string getData(string i);

  	void setMemory(string s1, string s2);

  	void printDataMemory();

	protected:

	map<string,string> myContents;
};
#endif
