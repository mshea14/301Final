
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

   

class RegisterFile{
 	public:

  	RegisterFile();

  	addToFile(string s);

 	&string getRegister(int i);

  	setRegister(int i, string s);

  	printRegisterFile();

	private:

	vector<string> myContents;
};