#include "Instruction.h"
#include "Opcode.h"



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



Instruction::INS Instruction::getControlValues(){
  INS controlValues;
  OpcodeTable opcodeTab;

  //RTYPE 
  if(stoi(opcodeTab.getOpcodeField(this-> myOpcode))==000000){
    controlValues.RegDst="1";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="1";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  } else if(stoi(opcodeTab.getOpcodeField(this-> myOpcode)) == 100011){
    controlValues.RegDst="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="1";
    controlValues.Regwrite="1";
    controlValues.MemRead="1";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }else if(stoi(opcodeTab.getOpcodeField(this-> myOpcode)) == 101011){
    controlValues.RegDst="X";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="1";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }else if(stoi(opcodeTab.getOpcodeField(this-> myOpcode)) == 000100){
    controlValues.RegDst="X";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="1";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="1";
    controlValues.Jump="0";
  }else if(stoi(opcodeTab.getOpcodeField(this-> myOpcode))== 001000){
    controlValues.RegDst="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }
  //jump
  else if(stoi(opcodeTab.getOpcodeField(this-> myOpcode))== 000010){
    controlValues.RegDst="X";
    controlValues.ALUSrc="X";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="X";
    controlValues.ALUOp0="X";
    controlValues.Jump="1";
  }

  return controlValues;

}


void Instruction::printControlValues(){
    //print control lines
  cout <<  "Control Line - RegDst: 0x" << this->myControlValues.RegDst << endl;
  cout <<  "Control Line - ALUSrc: 0x" << this->myControlValues.ALUSrc << endl;
  cout <<  "Control Line - MemToReg: 0x" << this->myControlValues.MemtoReg << endl;
  cout <<  "Control Line - RegWrite: 0x" <<this->myControlValues.Regwrite << endl;
  cout <<  "Control Line - MemRead: 0x" << this->myControlValues.MemRead << endl;
  cout <<  "Control Line - MemWrite: 0x" << this->myControlValues.MemWrite << endl;
  cout <<  "Control Line - Branch: 0x" << this->myControlValues.Branch << endl;
  cout <<  "Control Line - ALUOp1: 0x" << this->myControlValues.ALUOp1 << endl;
  cout <<  "Control Line - ALUOp0: 0x" <<this->myControlValues.ALUOp0 << endl;
  cout << "Control Line - Jump: 0x" <<this->myControlValues.ALUOp0 << endl;
}
