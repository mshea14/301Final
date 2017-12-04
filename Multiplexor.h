//* Author: Maddie Shea
//* Date:   October 28 2017
#ifndef __MULTIPLEXER_  // look to see whether __MYCONTAINER_H__ is defined
#define __MULTIPLEXER_  // if it's not, define it -- will prevent multiple includes
#include <string>
#include <iostream>
#include "Operation.h"

using namespace std;

class Multiplexor
{
private:
	string input0;
	string input1;
	string output;
	bool debug;
	bool writeToFile;
	bool control;
	Operation o;


public:
	Multiplexor();
	void setControl(bool control); 
	void setInputOne(string input);
	void setInputZero(string input);
	string getOutput();
	void execute();
	void SetDebugAndFile(bool debug, bool toFile);
	

};
#endif
