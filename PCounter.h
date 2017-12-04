#ifndef PCounter_hpp
#define PCounter_hpp


#include <iostream> 
#include "Operation.h"


using namespace std;
class PCounter
{
protected: 
	string address;
	Operation operate;
	bool debug;
	bool writeToFile;


public:

	PCounter();
	void setAddress(string newAddress);
	string getAddress();
	void setDebugAndWriteToFile(bool toDebug, bool toFile);
};

#endif