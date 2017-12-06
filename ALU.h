#ifndef ALU_h
#define ALU_h

#include <iostream>
#include <string>
#include <sstream>
#include "Operation.h"

using namespace std;

class ALU{

private:

public:

	//Default Constructor
	ALU();
    
    Operation o;
    
    string operation;
    
    void runALU(string op);
    
    void setOperation(string op);

	void compareLessThan();
	void setOperand1(string operand);
	void setOperand2(string operand);
	string getOutput();
	bool getComparedResult();
	void SetDebugAndFile(bool toDebug, bool toFile);

    string add(string operand1, string operand2);
    string sub(string operand1, string operand2);
    void compareEqual(string operand1, string operand2);
    void compareLessThan(string operand1, string operand2);
    bool comparedResult;
    
    string output;
    string operand1;
    string operand2;
    bool debug;
    bool writeToFile;

};

#endif
