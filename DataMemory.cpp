#include "DataMemory.h"
#include "math.h"
#include <iostream>
#include <vector>

DataMemory::DataMemory(){

}

void DataMemory::addToMemory(string s1,string s2){
	myContents.insert(pair<string,string>(s1,s2));
}

string DataMemory::getData(string i){

	return myContents.find(i) -> second;
}

void DataMemory::setMemory(string s1, string s2){

	myContents.find(s1)->second= s2;
}

void DataMemory::printDataMemory(string filename){
	ofstream outputFile (filename);

	for(auto it = myContents.cbegin(); it != myContents.cend(); ++it)
	{
    	outputFile<< it->first << ":" << "0x"<< it->second << endl;
	}	
	outputFile.close();
}

void DataMemory::printDataMemoryToTerminal(string filename){
	cout << "Data Memory Output" << endl;

	for(auto it = myContents.cbegin(); it != myContents.cend(); ++it)
	{
    	cout<< it->first << ":" << "0x"<< it->second << endl;
	}	
}