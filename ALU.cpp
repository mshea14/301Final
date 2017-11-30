
#include "ALU.h"



//Default Constructor

ALU::ALU(){

}


string ALU::add(string operand1, string operand2){
	if(debug){
		cout << "0th input to multiplexor: " << operand1 << endl;
		cout << "1st input to multiplexor: " << operand2 << endl;
	}
	
	int temp1 = cvtNumString2Number(operand1);
	int temp2 = cvtNumString2Number(operand2);

	int sum = temp1 + temp2;

	output = cvtNumString2Number(sum);

	if(debug) cout << "Output of add ALU: " << output << endl;

	return output;

}

string ALU::sub(string operand1, string operand2){

	if(debug){
		cout << "0th input to multiplexor: " << operand1 << endl;
		cout << "1st input to multiplexor: " << operand2 << endl;
	}
	
	int temp1 = cvtNumString2Number(operand1);
	int temp2 = cvtNumString2Number(operand2);

	int sum = temp1 - temp2;

	output = cvtNumString2Number(sum);

	if(debug) cout << "Output of subtract ALU: " << output << endl;

	return output;
}

void ALU::compareEqual(string operand1, string operand2){

	if(operand1.compare(operand2) != 0){
		if (debug) cout << "The strings are not equal" << endl;
		comparedResult = false;
	} else {
		if (debug) cout << "The strings are equal" << endl;
		comparedResult = true;
	}

}


//Compares two operands, returns true if first operand is smaller, false if larger

void ALU::compareLessThan(){
	if(cvtNumString2Number(BinaryToHex(operand1)) < cvtNumString2Number(BinaryToHex(operand2))){
		if(debug){
			cout << "Operand 1 is smaller than Operand 2" << endl;
		}
		output = BinaryToHex(cvtNumString2Number(1)); //1 = true
	}else{
		if(debug){
			output = BinaryToHex(cvtNumString2Number(0)); //0 = false
		}
	}
}

void ALU::setOperand1(string operand){
	if(debug){
		cout << "Setting Operand1 to: " << BinaryToHex(operand) << endl;
		operand1 = operand;
	}
}


void ALU::setOperand2(string operand){
	if(debug){
		cout << "Setting Operand2 to: " << BinaryToHex(operand) << endl;
		operand2 = operand;
	}
}

string ALU::getOutput(){
	if (debug){
		cout << "ALU Output: " << BinaryToHex(output) << endl;
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

















