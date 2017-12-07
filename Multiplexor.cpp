//* Author: Maddie Shea
//* Date:   October 28 2017

#include "Multiplexor.h"
#include "Operation.h"

	Multiplexor::Multiplexor()
	{

	}

	//set control
	void Multiplexor::setControl(string OneorZero)
	{
		bool control;
		if((OneorZero.compare("1"))==0) control = true;
		else control =false;
		if(debug)
		{
			cout << "Setting Multiplexor control to:   " << control<<  endl;
		}

		control = control;

		execute();
	}

	//the 1 input to multiplexor
	//input hex string
	void Multiplexor::setInputOne(string input)
	{
		
		if(debug)
		{
			cout << "1 input to Multiplexor: " << o.BinaryToHex(input) << endl;
		}
		
		input1 = input;
		execute();
	}

	//the 0 input to multiplexor
	//input hex string
	void Multiplexor::setInputZero(string input)
	{
	
		if(debug)
		{
			cout << "0 input to Multiplexor" << o.BinaryToHex(input) << endl;
		}
		
		input0 = input;
		execute();
	}

	//print out output
	string Multiplexor::getOutput()
	{


		if(debug)
		{
			cout << "Multiplexor output: " << (output) << endl;
		}

		return output;
	}

	void Multiplexor::SetDebugAndFile(bool toDebug, bool toFile)
	{
		debug = toDebug;
		writeToFile = toFile;
	}

	//execute the multiplexor
	void Multiplexor::execute()
	{	
		if(control)
		{
			output=input1;
		}
		else
		{
			output= input0;
		}

	}
	


