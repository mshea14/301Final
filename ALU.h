
/*****************************************************************************
 * ALU
 * 
 * This is the Arithmetic Logic Unit class of the non-pipeline processor.
 * The Operand1 and Operand2 variables are set through their respective methods.
 * The compare methods return value depends on how the two operands compare.
 * The arithmetic methods (add & sub) return the sum & difference, respectively, 
 * of the two operands as a 32-bit hexademical string.
******************************************************************************/

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
