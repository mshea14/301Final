#ifndef Register_h
#define Register_h


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;
   

class RegisterFile{
 	public:

  	RegisterFile();

  	void addToFile(string s);

 	string getRegister(int i);

  	void setRegister(int i, string s);

  	void printRegisterFileTerminal(string filename);
    void printRegisterFile(string filename);
	private:

	vector<string> myContents;
};
#endif
