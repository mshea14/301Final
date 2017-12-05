#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Opcode.h"
#include "RegisterTable.h"
#include <sstream>
using namespace std;

/* This class provides an internal representation for a MIPS assembly instruction.
 * Any of the fields can be queried.  Additionally, the class stores a 32 bit binary
 * encoding of the MIPS instruction.
 */


class Instruction{
  

 public:

    Instruction(); //constructor
    Instruction(string str1, string s2, string s3, string s4);
    
    //get methods
    string getOpcode();
    string getRS();
    string getRD();
    string getRT();
    string getJumpAmount();
    string getImmediate();
    
    //prints instructions
    void print();
    
   string instructionString();

 private:
    string myOpcode;
    string myRS;
    string myRT;
    string  myRD;
    string myImmediate;
    string jumpTo;
    
    //parts of instruction string
    string part1;
    string part2;
    string part3;
    string part4;
  //INS myControlValues;

  string myEncoding;
};

#endif
