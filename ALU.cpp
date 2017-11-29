
#include "ALU.h"



main(){


}

//Default Constructor

ALU::ALU(){}


string ALU::add(operand1, operand2){

	if(debug){
		cout << "0th input to multiplexor: " << operand1 << endl;
		cout << "1st input to multiplexor: " << operand2 << endl;
	}
	
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int sum = temp1 + temp2;

	output = intToHex(sum);

	if(debug) cout << "Output of add ALU: " << output << endl;

	return output;

}

string ALU::sub(operand1, operand2){

	if(debug){
		cout << "0th input to multiplexor: " << operand1 << endl;
		cout << "1st input to multiplexor: " << operand2 << endl;
	}
	
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int sum = temp1 - temp2;

	output = intToHex(sum);

	if(debug) cout << "Output of subtract ALU: " << output << endl;

	return output;
}

void ALU::compareEquals(string operand1, string operand2){

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
	if(hexToInt(binaryToHex(operand1)) < hexToInt(binaryToHex(operand2))){
		if(debug){
			cout << "Operand 1 is smaller than Operand 2" << endl;
		}
		output = binaryToHex(intToHex(1)); //1 = true
	}else{
		if(debug){
			output = binaryToHex(intToHex(0)); //0 = false
		}
	}
}

void ALU::setOperand1(string operand){
	if(debug){
		cout << "Setting Operand1 to: " << binaryToHex(operand) << endl;
		operand1 = operand;
	}
}


void ALU::setOperand2(string operand){
	if(debug){
		cout << "Setting Operand2 to: " << binaryToHex(operand) << endl;
		operand2 = operand;
	}
}

string ALU::getOutput(){
	if (debug){
		cout << "ALU Output: " << binaryToHex(output) << endl;
	}
	return output;
}

bool ALU::getComparedResult(){
	if(debug){
		cout << "Compared Result: " << comparedResult << endl;
	}
	return comparedResult;
}

void ALU::setDebug(bool value){
	debug = value;
}
















