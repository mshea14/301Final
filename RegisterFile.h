
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string>


   

class RegisterFile{
 	public:

  	RegisterFile();

  	void addToFile(string s);

 	string getRegister(int i);

  	void setRegister(int i, string s);

  	void printRegisterFile();

	private:

	vector<string> myContents;
};
