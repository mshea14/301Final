#include "DataMemory.h"
#include "math.h"
#include <iostream>
#include <vector>

DataMemory::DataMemory(){

}

//addes to memory 
void DataMemory::addToMemory(string s1,string s2){
	myContents.insert(pair<string,string>(s1,s2));
}

string DataMemory::getData(string i){

	return &myContents.find(i) -> second;
}


void DataMemory::setMemory(string s1, string s2){

	myContents.find(s1)->second= s2;
}

void DataMemory::printDataMemory(){
	ofstream outputFile ("output.txt");

	for(auto it = myContents.cbegin(); it != myContents.cend(); ++it)
	{
    	outputFile<< it->first << ":" << "0x"<< it->second << endl;
	}	
}

void DataMemory::shouldWrite(bool toWrite)
{
	if(debug) cout << "Data Memory should write " << endl;

	writeToData = toWrite;
}
    
void DataMemory::shouldRead(bool toRead)
{
	if(debug) cout << "Data Memory should read " << endl;

	readData = toRead;
}    

void DataMemory::SetDebugAndFile(bool toDebug, bool toFile)
{
	debug = toDebug;
	writeToFile = toFile;
}
