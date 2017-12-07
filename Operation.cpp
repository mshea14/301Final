//* Author: Maddie Shea
//* Date:   October 28 2017


#include "Operation.h"
#include <bitset>



	//taking an int and converting it to a hexadecimal string 
	string Operation::IntToHex(int num)
	{
		 char output[100];
	    sprintf(output, "%08x", num);
	    string result = output;
	    result = "0x" + result;
	    return result;
	}




	//converts hex string to int
	int Operation::cvtNumString2Number(string s)
	{
	    int x;   
	    stringstream stream;
	    stream << hex << s;
	    stream >> x;
	    return x;
	}
	
	//binary string to hex string	
	string Operation::BinaryToHex(string s)
	{
		if(s != ""){
		std::stringstream ss;
		ss << std::hex << std::stoll(s, NULL, 2);
	
		string s =  ss.str();
		while (s.length() != 8){
		    s = "0" + s;
		}
		s = "0x" + s;
		return s;
		
	    }
		return "0x";
	}

	//sign extends
	string Operation::SignExtend(string str)
	{
		if(debug)
		{
			cout << "Input to Sign Extend: " << BinaryToHex(str) << endl;
		}
		string  substring = str.substr(0,1);
		while(str.length()!=32)
		{
		  str= "0"+ str;
		}

		if(debug)
		{
			cout << "Output to Sign Extend: " << BinaryToHex(str) << endl;
		}

		return str;

	}

	//takes in address, shift left two 
	//outputs address to branch to 
	string Operation::ShiftLeftTwo(string address)
	{
		if(debug)
		{
			cout << "Shift Left input: " << "00" << BinaryToHex(address) << endl;

		}

		if(address.length() == 32)
		{
			address.erase(0,2); //remove first 2 digit 
		}

		address+="00";

		if(debug)
		{
			cout << "Shift Left output: " << BinaryToHex(address) << endl;
		}

		return address;

	}

	void Operation::SetDebugAndFile(bool toDebug, bool toFile)
	{
		debug = toDebug;
		writeToFile = toFile;
	}


	//input has 0x so start at index 2
	string Operation::HexToBinary(string hex)
	{
		string s = hex;
 	   stringstream ss;
    	ss << std::hex << s;
   	 unsigned n;
  	 ss >> n;
  	  bitset<32> b(n);
    
    
		return b.to_string();
}


