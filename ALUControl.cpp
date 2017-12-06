#include "ALUControl.h"

ALUControl::ALUControl()
{

} 

void ALUControl::setALU(ALU *alu) //setALU
{
	alu = aluToControl;
} 

//send control lines to multiplexors
void ALUControl::controlLines(string instructName)
{
	aluToControl->setOperation(instructName);

} 
