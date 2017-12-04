#include "Instruction.h"



Instruction::Instruction()
{
  myOpcode = UNDEFINED;
  myRS = myRT = myRD = NumRegisters;
}

Instruction::Instruction(Opcode op, Register rs, Register rt, Register rd, int imm)
// You can specify all the fields to initialize the Instruction
{
  setValues(op, rs, rt, rd, imm);
}

void Instruction::setValues(Opcode op, Register rs, Register rt, Register rd, int imm)
// You can specify all the fields to initialize the Instruction
{

  myOpcode = op;
  if(op < 0 || op >= UNDEFINED)
    myOpcode = UNDEFINED;

  myRS = rs;
  if(rs < 0 || rs >= NumRegisters)
    myRS = NumRegisters;

  myRT = rt;
  if(rt < 0 || rt >= NumRegisters)
    myRT = NumRegisters;

  myRD = rd;
  if(rd < 0 || rd >= NumRegisters)
    myRD = NumRegisters;

  myImmediate = imm;

  //  if(!( (imm & 0xFFFF0000) << 1))  // make sure it has nothing in upper 16 bits
  //    myImmediate = imm;  

}

string Instruction::getString()
// Returns a string which represents all of the fields 
{
  stringstream s ;
  s << "OP: \t" << myOpcode << "\t" << "RD: " << myRD << "\t" << 
    "RS: " << myRS << "\t" << "RT: " << "\t" << myRT << "\t" <<
    "Imm: " << myImmediate;
  
  return s.str();
  
}

INS Instruction::getControlValues(){
  INS controlValues;

  if(this-> myOpcode == 000000){
    controlValues.RegDest="1";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="1";
    controlValues.ALUOp0="0";
  } else if(this-> myOpcode == 100011){
    controlValues.RegDest="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="1";
    controlValues.Regwrite="1";
    controlValues.MemRead="1";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
  }else if(this-> myOpcode == 101011){
    controlValues.RegDest="X";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="1";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
  }else if(this-> myOpcode == 000100){
    controlValues.RegDest="X";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="1";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="1";
  }else if(this-> myOpcode == 001000){
    controlValues.RegDest="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
  }else if(this-> myOpcode == 000010){
    controlValues.RegDest="X";
    controlValues.ALUSrc="X";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="X";
    controlValues.ALUOp0="X";
  }
}