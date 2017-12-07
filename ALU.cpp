
#include "ALU.h"



//Default Constructor

ALU::ALU(){

}

//takes in two binary strings 
//return hex value of addition
string ALU::add(string operand1, string operand2){
	if(debug){
		cout << "0th input to multiplexor: " << o.BinaryToHex(operand1) << endl;
		cout << "1st input to multiplexor: " << o.BinaryToHex(operand2) << endl;
	}
	operand1ALU=operand1;
	operand2ALU=operand2;

	cout << operand1 << endl;
	int temp1 = o.cvtNumString2Number( o.BinaryToHex(operand1));
	int temp2 = o.cvtNumString2Number(o.BinaryToHex(operand2));

	int sum = temp1 + temp2;
	cout << temp1 << endl;
	

	output = o.IntToHex(sum);

	if(debug) cout << "Output of add ALU: " << output << endl;

	return output;

}

//takes in two binary strings
//returns hex value of subtraction 
string ALU::sub(string operand1, string operand2){

	if(debug){
		cout << "0th input to multiplexor: " << o.BinaryToHex(operand1) << endl;
		cout << "1st input to multiplexor: " << o.BinaryToHex(operand2) << endl;
	}
	operand1ALU=operand1;
	operand2ALU=operand2;

cout << operand1ALU << endl;
	
	int temp1 = o.cvtNumString2Number(o.BinaryToHex(operand1));
	int temp2 = o.cvtNumString2Number(o.BinaryToHex(operand2));

	int sum = temp1 - temp2;

	output = o.IntToHex(sum);

	if(debug) cout << "Output of subtract ALU: " << output << endl;

	return output;
}

//takes in two binary strings and compares them 
void ALU::compareEqual(string operand1, string operand2){
operand1ALU=operand1;
	operand2ALU=operand2;
	if(operand1.compare(operand2) != 0){
		if (debug) cout << "The strings are not equal" << endl;
		comparedResult = false;
	} else {
		if (debug) cout << "The strings are equal" << endl;
		comparedResult = true;
	}

}


//Compares two operands, returns true if first operand is smaller, false if larger

void ALU::compareLessThan(string operand1, string operand2){
operand1ALU=operand1;
	operand2ALU=operand2;
	if(o.cvtNumString2Number(o.BinaryToHex(operand1)) < o.cvtNumString2Number(o.BinaryToHex(operand2))){
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
		operand1ALU = operand;
	}
}


void ALU::setOperand2(string operand){
	if(debug){
		cout << "Setting Operand2 to: " << o.BinaryToHex(operand) << endl;
		operand2ALU = operand;
	}
}

string ALU::getOutput(){
	if (debug){

		cout << "ALU Output: " << output << endl;
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
		add(operand1ALU, operand2ALU);
	}
	else if(op.compare("less")==0)
	{
		if(debug) cout << "ALU checking less than or equal" << endl;
		compareLessThan(operand1ALU, operand2ALU);		
	}
	else if(op.compare("equal")==0)
	{
		if(debug) cout << "ALU checking equality" << endl;
		compareEqual(operand1ALU, operand2ALU);
	}
	else if(op.compare("subtract")==0)
	{
		if(debug) cout << "ALU subtracting" << endl;
		sub(operand1ALU, operand2ALU);
	}

}

void ALU::setOperation(string op)
{
	operation = op;
}















