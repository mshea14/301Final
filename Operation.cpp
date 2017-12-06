//* Author: Maddie Shea
//* Date:   October 28 2017


#include "Operation.h"



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
		string rest("0x"),tmp,chr = "0000";
		int len = s.length()/4;
		chr = chr.substr(0,len);
		s = chr+s;
		for (int i=0;i<s.length();i+=4)
		{
			tmp = s.substr(i,4);
			if (!tmp.compare("0000"))
			{
				rest = rest + "0";
			}
			else if (!tmp.compare("0001"))
			{
				rest = rest + "1";
			}
			else if (!tmp.compare("0010"))
			{
				rest = rest + "2";
			}
			else if (!tmp.compare("0011"))
			{
				rest = rest + "3";
			}
			else if (!tmp.compare("0100"))
			{
				rest = rest + "4";
			}
			else if (!tmp.compare("0101"))
			{
				rest = rest + "5";
			}
			else if (!tmp.compare("0110"))
			{
				rest = rest + "6";
			}
			else if (!tmp.compare("0111"))
			{
				rest = rest + "7";
			}
			else if (!tmp.compare("1000"))
			{
				rest = rest + "8";
			}
			else if (!tmp.compare("1001"))
			{
				rest = rest + "9";
			}
			else if (!tmp.compare("1010"))
			{
				rest = rest + "A";
			}
			else if (!tmp.compare("1011"))
			{
				rest = rest + "B";
			}
			else if (!tmp.compare("1100"))
			{
				rest = rest + "C";
			}
			else if (!tmp.compare("1101"))
			{
				rest = rest + "D";
			}
			else if (!tmp.compare("1110"))
			{
				rest = rest + "E";
			}
			else if (!tmp.compare("1111"))
			{
				rest = rest + "F";
			}
			else
			{
				continue;
			}
		}
		return rest;
    

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
			str.append(substring,0);
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
		string sReturn = "";
			for (int i = 2; i < hex.length (); ++i)
			{
				switch (hex [i])
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


