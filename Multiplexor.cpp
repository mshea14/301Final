//* Author: Maddie Shea
//* Date:   October 28 2017

#include "Multiplexor.h"

class Multiplexor
{
	

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
		if(debug)
		{
			cout << "1 input to Multiplexor: " << Operation.HexToBinary(input) << endl;
		}
		
		input1 = input;
		execute();
	}

	//the 0 input to multiplexor
	void Multiplexor::setInputZero(string input)
	{
		if(debug)
		{
			cout << "0 input to Multiplexor" << Operation.HexToBinary(input) << endl;
		}
		
		input0 = input;
		execute();
	}

	//print out output
	string Multiplexor::getOutput()
	{
		if(debug)
		{
			cout << "Multiplexor output: " << Operation.HexToBinary(output) << endl;
		}

		return output;
	}

	SetDebugAndFile(bool toDebug, bool toFile)
	{
		debug = toDebug;
		writeToFile = toFile;
	}

	//execute the multiplexor
	void execute()
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
	s

}
