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

 	string getData(int i);

  	void setMemory(string s1, string s2);

  	void printDataMemory();

	private:

	map<int,string> myContents;
};
#endif
