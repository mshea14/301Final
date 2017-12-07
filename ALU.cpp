
#include "ALU.h"



//Default Constructor

ALU::ALU(){

}

//takes in two binary strings 
//return hex value of addition
string ALU::add(){
	if(debug){
		cout << "0th input to ALU: " << o.BinaryToHex(operand1ALU) << endl;
		cout << "1st input to ALU: " << o.BinaryToHex(operand2ALU) << endl;
	}

	cout << operand1ALU << endl;
	cout << operand2ALU << endl;
	cout <<  o.HexToBinary(operand1ALU) << endl;
	cout <<  o.HexToBinary(operand2ALU) << endl;
	int temp1 = o.cvtNumString2Number( o.HexToBinary(operand1ALU));
	int temp2 = o.cvtNumString2Number(o.HexToBinary(operand2ALU));

	int sum = temp1 + temp2;


	output = (o.IntToHex(sum));

	if(debug) cout << "Output of add ALU: " << o.BinaryToHex(output) << endl;
	return output;

}

//takes in two binary strings
//returns hex value of subtraction 
string ALU::sub(){

	if(debug){
		cout << "0th input to ALU: " << o.BinaryToHex(operand1ALU) << endl;
		cout << "1st input to ALU: " << o.BinaryToHex(operand2ALU) << endl;
	}

	
	int temp1 = o.cvtNumString2Number(o.BinaryToHex(operand1ALU));
	int temp2 = o.cvtNumString2Number(o.BinaryToHex(operand2ALU));

	int sum = temp1 - temp2;

	output = o.IntToHex(sum);

	if(debug) cout << "Output of subtract ALU: " << o.BinaryToHex(output) << endl;

	return output;
}

//takes in two binary strings and compares them 
void ALU::compareEqual(){

	if(operand1ALU.compare(operand2ALU) != 0){
		if (debug) cout << "The strings are not equal" << endl;
		comparedResult = false;
	} else {
		if (debug) cout << "The strings are equal" << endl;
		comparedResult = true;
	}

}


//Compares two operands, returns true if first operand is smaller, false if larger

void ALU::compareLessThan(){

	if(o.cvtNumString2Number(o.BinaryToHex(operand1ALU)) < o.cvtNumString2Number(o.BinaryToHex(operand2ALU))){
		if(debug){
			cout << "Operand 1 is smaller than Operand 2" << endl;
		}
		output = o.BinaryToHex("00000000000000000000000000000001"); //1 = true
	}else{
		if(debug){
			output = o.BinaryToHex("00000000000000000000000000000000"); //0 = false
		}
	}
}

void ALU::setOperand1(string operand){
	if(debug){
		cout << "Setting Operand1 to: " << o.BinaryToHex(operand) << endl;

	}
	operand1ALU = operand;
}


void ALU::setOperand2(string operand){
	if(debug){
		cout << "Setting Operand2 to: " << o.BinaryToHex(operand) << endl;
		
	}
	operand2ALU = operand;
}

string ALU::getOutput(){
	if (debug){

		cout << "ALU Output: " << o.BinaryToHex(output) << endl;
	}
	return output;
}

bool ALU::getComparedResult(){
	if(debug){
		cout << "Compared Result: " << comparedResult << endl;
	}
	return comparedResult;
}

void ALU::SetDebugAndFile(bool toDebug, bool toFile)
{
	writeToFile = toFile;
	debug = toDebug;
}


void ALU::runALU(string op)
{
	if(debug) 
	{
		cout << "Input 0 to ALU" << o.BinaryToHex(operand1ALU) << endl;
		cout << "Input 1 to ALU" << o.BinaryToHex(operand2ALU) << endl;
	}


	if(op.compare("add")==0)
	{
		if(debug) cout << "ALU adding" << endl;
		add();
	}
	else if(op.compare("less")==0)
	{
		if(debug) cout << "ALU checking less than or equal" << endl;
		compareLessThan();		
	}
	else if(op.compare("equal")==0)
	{
		if(debug) cout << "ALU checking equality" << endl;
		compareEqual();
	}
	else if(op.compare("subtract")==0)
	{
		if(debug) cout << "ALU subtracting" << endl;
		sub();
	}

}

void ALU::setOperation(string op)
{
	operation = op;
}















