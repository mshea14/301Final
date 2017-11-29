//* Author: Maddie Shea
//* Date:   October 28 2017


#include "Operation.h"

Operation
{


	//taking an int and converting it to a hexadecimal string 
	string Operation::IntToHex(int num)
	{
		stringstream stream;
		stream << hex << num;
		return string result( stream.str() );
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
		int result =0 ;

	    for(size_t count = 0; count < s.length() ; ++count)
	    {
	        result *=2;
	        result += s[count]=='1'? 1 :0;
	    }  

	    stringstream ss;
	    ss << "0x" << hex << setw(8) << setfill('0')  << result;

	    return string hexVal(ss.str());
    

	}

	//sign extends
	string Operation::SignExtend(string str)
	{
		if(debug)
		{
			cout << "Input to Sign Extend: " << BinaryToHex(str) << endl;
		}
		string substring = str.substr(0,1);
		while(str.length()!=32)
		{
			str.append(0, substring);
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

	Operation::SetDebugAndFile(bool toDebug, bool toFile)
	{
		debug = toDebug;
		writeToFile = toFile;
	}


}