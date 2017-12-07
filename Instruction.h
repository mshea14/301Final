#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Opcode.h"
#include "RegisterTable.h"
#include <sstream>

/* This class provides an internal representation for a MIPS assembly instruction.
 * Any of the fields can be queried.  Additionally, the class stores a 32 bit binary
 * encoding of the MIPS instruction.
 */


class Instruction{
    


 public:
    
    struct INS{
        
        string RegDst;
        string ALUSrc;
        string MemtoReg;
        string Regwrite;
        string MemRead;
        string MemWrite;
        string Branch;
        string ALUOp1;
        string ALUOp0;
        string Jump;
    };
  Instruction();
    
   

  // You can specify all the fields to initialize the Instruction
  Instruction(Opcode op, Register rs, Register rt, Register rd, int imm);
  ~Instruction() {};

  // Allows you to specify all the fields of the Instruction
  void setValues(Opcode op, Register rs, Register rt, Register rd, int imm);

  // Returns the various fields for the Instruction
  Opcode getOpcode()   { return myOpcode;};
  Register getRS()     { return myRS; };
  Register getRD()     { return myRD; };
  Register getRT()     { return myRT; };
  int getImmediate()   { return myImmediate; };
  INS getControlValues(string opcode) ;


  // Returns a string which represents all of the fields 
  string getString();

  // Stores the 32 bit binary encoding of MIPS instruction passed in
  void setEncoding(string s) { myEncoding = s;};

  // Returns string representing the 32 binary encoding of MIPS instruction
  string getEncoding() { return myEncoding; };


    
 private:
  Opcode myOpcode;
  Register myRS;
  Register myRT;
  Register myRD;
  int myImmediate;
  INS myControlValues;

  string myEncoding;
};

#endif
