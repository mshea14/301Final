using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <map>
   

class DataMemory{
 	public:

    //constructor
  	DataMemory();
    
  	void addToMemory(string s1,string s2);

 	string getData(string i);

  	void setMemory(string s1, string s2);

  	void printDataMemory();
    
    void shouldWrite(bool toWrite);
    
    void shouldRead(bool toRead);
    
    void SetDebugAndFile(bool toDebug, bool toFile);
    
    //booleans
    bool debug;
    bool writeToFile;
    bool writeToData;
    bool readData;
    

	private:

	map<int,string> myContents;
};
