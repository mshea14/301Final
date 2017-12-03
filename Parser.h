using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

class Parser{

	public:

	Parser();

	&ConfigFile parseConfigFile(string filename);

	&RegisterFile parseRegister(string filename);

	&DataMemory parseMemory(string filename);

};