#include "Opcode.h"



OpcodeTable::OpcodeTable()
// Initializes all the fields for every instruction in Opcode enum
{
  myArray[ADD].name = "add";  myArray[ADD].numOps = 3;   myArray[ADD].rdPos = 0;  
  myArray[ADD].rsPos = 1;  myArray[ADD].rtPos = 2;   myArray[ADD].immPos = -1;  
  myArray[ADD].instType = RTYPE; myArray[ADD].op_field = "000000"; myArray[ADD].funct_field = "100000";


  myArray[ADDI].name = "addi";  
  myArray[ADDI].numOps = 3;   myArray[ADDI].rdPos = -1;  myArray[ADD].rtPos = 0;  myArray[ADDI].rsPos = 1;  myArray[ADDI].immPos = -1;  
  myArray[ADDI].instType = ITYPE; myArray[ADDI].op_field = "001000"; myArray[ADDI].funct_field = "";


  myArray[SUB].name = "sub";  
  myArray[SUB].numOps = 3;   myArray[SUB].rdPos = 0;  myArray[SUB].rtPos = 2;  myArray[SUB].rsPos = 1; myArray[SUB].immPos = -1;  
  myArray[SUB].instType = RTYPE; myArray[SUB].op_field = "000000"; myArray[SUB].funct_field = "100010";


  myArray[LW].name = "lw";  
  myArray[LW].numOps = 2;   myArray[LW].rdPos = -1;  myArray[LW].rsPos = -1;  myArray[LW].rtPos = 0;   myArray[LW].immPos = 1;  
  myArray[LW].instType = ITYPE; myArray[LW].op_field = "100011"; myArray[LW].funct_field = "";


  myArray[SW].name = "sw";  myArray[SW].numOps = 2;   myArray[SW].rdPos = -1;  
  myArray[SW].rsPos = -1;  myArray[SW].rtPos = 0;   myArray[SW].immPos = 1;  
  myArray[SW].instType = ITYPE; myArray[SW].op_field = "101011"; myArray[SW].funct_field = "";


  myArray[BEQ].name = "beq";  myArray[BEQ].numOps = 3;   myArray[BEQ].rdPos = -1; 
   myArray[BEQ].rsPos = 1;  myArray[BEQ].rtPos = 0;   myArray[BEQ].immPos = -1;  
   myArray[BEQ].instType = ITYPE; myArray[BEQ].op_field = "000100"; myArray[BEQ].funct_field = ""; myArray[BEQ].immLabel=1;


  myArray[J].name = "j";  myArray[J].numOps = 1;   myArray[J].rdPos = -1;  
  myArray[J].rsPos = -1;  myArray[J].rtPos = -1;   myArray[J].immPos = -1;  
  myArray[J].instType = JTYPE; myArray[J].op_field ="000010"; myArray[J].funct_field = ""; myArray[J].immLabel=0;


}

Opcode OpcodeTable::getOpcode(string str)
// Given a valid MIPS assembly mnemonic, returns an Opcode which represents a 
// template for that instruction.
{
  for(int i = 0; i < (int)UNDEFINED; i++){
    if(myArray[i].name == str){
      return (Opcode)i;
    }
  }
  return UNDEFINED;
}

int OpcodeTable::numOperands(Opcode o)
// Given an Opcode, returns number of expected operands.
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].numOps;
}


int OpcodeTable::RSposition(Opcode o)
// Given an Opcode, returns the position of RS field.  If field is not
// appropriate for this Opcode, returns -1.
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rsPos;
}

int OpcodeTable::RTposition(Opcode o)
// Given an Opcode, returns the position of RT field.  If field is not
// appropriate for this Opcode, returns -1.
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rtPos;
}

int OpcodeTable::RDposition(Opcode o)
// Given an Opcode, returns the position of RD field.  If field is not
// appropriate for this Opcode, returns -1.
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rdPos;
}

int OpcodeTable::IMMposition(Opcode o)
// Given an Opcode, returns the position of IMM field.  If field is not
// appropriate for this Opcode, returns -1.
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].immPos;
}

InstType OpcodeTable::getInstType(Opcode o)
// Given an Opcode, returns instruction type.
{
  if(o < 0 || o > UNDEFINED)
    return (InstType)-1;
  return myArray[o].instType;
}

string OpcodeTable::getOpcodeField(Opcode o)
// Given an Opcode, returns a string representing the binary encoding of the opcode
// field.
{
  if(o < 0 || o > UNDEFINED)
    return string("");
  return myArray[o].op_field;
}

string OpcodeTable::getFunctField(Opcode o)
// Given an Opcode, returns a string representing the binary encoding of the function
// field.
{
  if(o < 0 || o > UNDEFINED)
    return string("");
  return myArray[o].funct_field;
}

bool OpcodeTable::isIMMLabel(Opcode o)
// Given an Opcode, returns true if instruction expects a label in the instruction.
// See "J".
{
  if(o < 0 || o > UNDEFINED)
    return false;
  return myArray[o].immLabel;
}
