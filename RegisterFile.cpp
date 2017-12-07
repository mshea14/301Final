#include "RegisterFile.h"
#include "math.h"
#include <iostream>
#include <vector>

RegisterFile::RegisterFile(){

}

void RegisterFile::addToFile(string s){
	myContents.push_back(s);
}

string RegisterFile::getRegister(int i){
	return myContents[i];
}

void RegisterFile::setRegister(int i, string s){
	myContents[i]= s;
}

void RegisterFile::printRegisterFile(string filename){
	ofstream outputFile (filename);

	for(int i = 0; i <myContents.size(); i++){
		outputFile << i << ":";
		outputFile <<"0x";
		outputFile << myContents[i] << endl;
	}
}

void RegisterFile::printRegisterFileTerminal(string filename){

	for(int i = 0; i <myContents.size(); i++){
		cout << i << ":";
		cout <<"0x";
		cout << myContents[i] << endl;
	}
}
