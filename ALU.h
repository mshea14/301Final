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

	void setOperand1(string operand);
	void setOperand2(string operand);
	string getOutput();
	bool getComparedResult();
	void SetDebugAndFile(bool toDebug, bool toFile);

    string add();
    string sub();
    void compareEqual();
    void compareLessThan();
    bool comparedResult;
    
    string output;
    string operand1ALU;
    string operand2ALU;
    bool debug;
    bool writeToFile;

};

#endif
