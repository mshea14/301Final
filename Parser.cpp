#include "Parser.h"
#include "RegisterFile.h"
#include "DataMemory.h"
#include "ConfigFile.h"
#include "math.h"
#include "string.h"
#include <stringstream>
#include <iostream>

Parser::Parser(){

}

&ConfigFile Parser::parseConfigFile(string filename){
	
	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cout<< "Cannot open input file";
  	}else{
    	string line;
    }

    vector<string> info;
    while(getline(in, line)){
    	if(line[0] != '#' && line[0] != ' '){
    		    		stringstream info(line);
			string segment;
			vector<string> seglist;

			while(getline(info, segment, ':')){
   				seglist.push_back(segment);
			}
			info.push_back(seglist[1]);
    	}
    }
    ConfigFile input = ConfigFile(info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7], info[8]);
    return &input;
}

&RegisterFile Parser::parseRegister(string filename){

	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cout<< "Cannot open input file";
  	}else{
    	string line;
    }
    
    RegisterFile input = RegisterFile();
    while(getline(in, line)){
    	if(line[0] != '#'){
    		if(line[1] == ':'){
    			if(line[3] == 'x'){
    				string content =line.substr(4,10);
    				input.addToFile(content);
    			}else{
    				string content =line.substr(2,10);
    				input.addToFile(content);
    			}
    		} else {
    			if(line[4] == 'x'){
    				string content =line.substr(5,10);
    				input.addToFile(content);
    			}else{
    				string content =line.substr(3,10);
    				input.addToFile(content);
    			}
    		}
    	}
    }
    return &RegisterFile;
}
DataMemory Parser::parseMemory(string filename){

	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cout<< "Cannot open input file";
  	}else{
    	string line;
    }

    DataMemory input = DataMemory();
    while(getline(in, line)){
    	if(line[0] != '#'){
    		stringstream info(line);
			string segment;
			vector<string> seglist;

			while(getline(info, segment, ':')){
   				seglist.push_back(segment);
			}
			input.addToMemory(seglist[0], seglist[1])
    	}
    }
}