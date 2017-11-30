//* Author: Maddie Shea
//* Date:   October 28 2017


#include "Operation.h"



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


	//input has 0x so start at index 2
	string Operation::HexToBinary(string hex)
	{
		string sReturn = "";
			for (int i = 2; i < h.length (); ++i)
			{
				switch (sHex [i])
				{
					case '0': sReturn.append ("0000"); break;
					case '1': sReturn.append ("0001"); break;
					case '2': sReturn.append ("0010"); break;
					case '3': sReturn.append ("0011"); break;
					case '4': sReturn.append ("0100"); break;
					case '5': sReturn.append ("0101"); break;
					case '6': sReturn.append ("0110"); break;
					case '7': sReturn.append ("0111"); break;
					case '8': sReturn.append ("1000"); break;
					case '9': sReturn.append ("1001"); break;
					case 'a': sReturn.append ("1010"); break;
					case 'b': sReturn.append ("1011"); break;
					case 'c': sReturn.append ("1100"); break;
					case 'd': sReturn.append ("1101"); break;
					case 'e': sReturn.append ("1110"); break;
					case 'f': sReturn.append ("1111"); break;
				}
			}
			return sReturn;
	}


