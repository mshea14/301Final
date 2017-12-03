#include "DataMemory.h"
#include "math.h"
#include <iostream>
#include <vector>

DataMemory::DataMemory(){

}

DataMemory::addToMemory(string s1,string s2){
	myContents.insert(pair<string,string>(s1,s2));
}

&string DataMemory::getData(string i){

	return &myContents.find(i) -> second;
}

DataMemory::setMemory(string s1, string s2){

	myContents.find(s1)->second= s2;
}

DataMemory::printDataMemory(){
	ofstream outputFile ("output.txt");

	for(auto it = myContents.cbegin(); it != myContents.cend(); ++it)
	{
    	outputFile<< it->first << ":" << "0x"<< it->second << endl;
	}	
}