//* Author: Maddie Shea
//* Date:   October 28 2017
#ifndef __OPERATION_  // look to see whether __MYCONTAINER_H__ is defined
#define __OPERATION_  // if it's not, define it -- will prevent multiple includes
#include <string> 
#include <sstream>
#include <iomanip>



class Operation
{
	private:
		bool debug;
		bool writeToFile;


	public:
		string IntToHex(int num); //converts int to a string representing hexadecimal value
		int cvtNumString2Number(string s); //converts hex string to int
		string BinaryToHex(string binary); //returns hex value of binary string 
		string SignExtend(string str); 
		string ShiftLeftTwo(string address);
		void SetDebugAndFile(bool debug, bool toFile);

	

} 
#endif
