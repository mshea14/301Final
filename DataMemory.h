using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

   

class DataMemory{
 	public:

  	DataMemory();

  	addToMemory(string s1,string s2);

 	&string getData(int i);

  	setMemory(string s1, string s2);

  	printDataMemory();

	private:

	map<int,string> myContents;
};