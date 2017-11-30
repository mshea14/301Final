//* Author: Maddie Shea
//* Date:   October 28 2017

#include "Multiplexor.h"
#include "Operation.h"

	Multiplexor::Multiplexor()
	{

	}

	//set control
	void Multiplexor::setControl(bool newControl)
	{
		if(debug)
		{
			cout << "Setting Multiplexor control to:   " << newControl<<  endl;
		}

		control = newControl;

		execute();
	}

	//the 1 input to multiplexor
	void Multiplexor::setInputOne(string input)
	{
		Operation o;
		if(debug)
		{
			cout << "1 input to Multiplexor: " << o.HexToBinary(input) << endl;
		}
		
		input1 = input;
		execute();
	}

	//the 0 input to multiplexor
	void Multiplexor::setInputZero(string input)
	{
		Operation o;
		if(debug)
		{
			cout << "0 input to Multiplexor" << o.HexToBinary(input) << endl;
		}
		
		input0 = input;
		execute();
	}

	//print out output
	string Multiplexor::getOutput()
	{
		Operation o;

		if(debug)
		{
			cout << "Multiplexor output: " << o.HexToBinary(output) << endl;
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
	


