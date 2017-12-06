#include "Parser.h"


Parser::Parser(){

}

void Parser::readAndPrintInstruction(int i, string filename){
	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cerr<< "Cannot open input file";
        exit(1);
  	}

    	string line;
    

    vector<string> info;
    while(getline(in, line)){
			info.push_back(line);
    	
    }

    cout << info[i] << endl;


}

ConfigFile Parser::parseConfigFile(string filename){
	
	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cerr<< "Cannot open input file";
        exit(1);
  	}
    string line;
    

    vector<string> info (10);
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
    bool bool1=true; bool bool2=true; bool bool3=true;
    if(info[4]== "false") { bool1= false;}
    if(info[5]== "false") { bool2= false;}
    if(info[6]== "false") { bool3= false;}
    ConfigFile input = ConfigFile(info[0], info[1], info[2], info[3], bool1, bool2, bool3, info[7]);
    return input;

}

RegisterFile Parser::parseRegister(string filename){

	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cerr<< "Cannot open input file";
        exit(1);
  	}
    	string line;
    
    RegisterFile reg = RegisterFile();
    while(getline(in, line)){
    	if(line[0] != '#'){
    		if(line[1] == ':'){
    			if(line[3] == 'x'){
    				string content =line.substr(4,10);
    				reg.addToFile(content);
    			}else{
    				string content =line.substr(2,10);
    				reg.addToFile(content);
    			}
    		} else {
    			if(line[4] == 'x'){
    				string content =line.substr(5,10);
    				reg.addToFile(content);
    			}else{
    				string content =line.substr(3,10);
    				reg.addToFile(content);
    			}
    		}
    	}
    }
    return reg;
}
DataMemory Parser::parseMemory(string filename){

	ifstream in;
  	in.open(filename.c_str());
  	if(in.bad()){
    	cerr<< "Cannot open input file";
        exit(1);
  	}
    	string line;
    

    DataMemory input = DataMemory();
    while(getline(in, line)){
    	if(line[0] != '#'){
    		stringstream info(line);
			string segment;
			vector<string> seglist;

			while(getline(info, segment, ':')){
   				seglist.push_back(segment);
			}
			input.addToMemory(seglist[0], seglist[1]);
    	}
    }

    return input;
}