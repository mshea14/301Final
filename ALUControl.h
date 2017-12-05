#ifndef _ALUControl_H
#define _ALUControl_H

#include "ALU.cpp"
using namespace std;

class ALUControl 
{
	
protected:

	string ALUOp;
	ALU *aluToControl;


public: 

	ALUControl(); //controller
	void setALU(ALU *alu); //setALU
	void controlLines(string opcode); //send control lines to multiplexors




};
#endif