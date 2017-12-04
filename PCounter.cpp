#include "PCounter.h"

//starts off PC at 0x00400000
PCounter::PCounter()
{
	address = operate.HexToBinary("0x00040000");
}

//sets the program counter's address to the input address
void PCounter::setAddress(string newAddress)
{
	if(debug)
	{
		cout << "Setting PC Counter to " << operate.BinaryToHex(address) << endl;
	}
	address = newAddress;
}

string PCounter::getAddress()
{
	if(debug)
	{
		cout << "PC counter is " << operate.HexToBinary(address) << endl;
	}
	return address;

}

void PCounter::setDebugAndWriteToFile(bool toDebug, bool toFile)
{
	debug = toDebug;
	writeToFile = toFile;
}