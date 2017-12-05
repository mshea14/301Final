#include "Instruction.h"



Instruction::Instruction(){}
//constructor

//look at setup of instructions given "some instruction $reg $reg w/out offset" or can be jump
Instruction::Instruction(string str1, string s2, string s3, string s4)
{
	part1 = str1;
    part2 = str2;
    part3 = str3;
    part4 = str4;
    
    str1.erase(remove(str1.begin(), str1.end(), '$'), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), '$'), str2.end());
    str3.erase(remove(str3.begin(), str3.end(), '$'), str3.end());
    str4.erase(remove(str4.begin(), str4.end(), '$'), str4.end());

    myOpcode = str1;
    jumpTo = "00000000000000000000000000";
    myImmediate = "0000000000000000";

    //add = 	add $rd, $rs, $rt
    //encoding 0000 00ss ssst tttt dddd d000 0010 0000
    if(myOpcode=="add")
    {
    	myRD = bitset< 5 >( stoi(str2)  ).to_string();
        myRS = bitset< 5 >( stoi(str3)  ).to_string();
        myRT = bitset< 5 >( stoi(str4)  ).to_string();

    }


    //sub = 	sub $rd, $rs, $rt
    //encoding 0000 00ss ssst tttt dddd d000 0010 0010
    else if(myOpcode=="sub")
    {
    	myRD = bitset< 5 >( stoi(str2)  ).to_string();
        myRS = bitset< 5 >( stoi(str3)  ).to_string();
        myRT = bitset< 5 >( stoi(str4)  ).to_string();
    }

    //addi $rt, $rs, imm
    //0010 00ss ssst tttt iiii iiii iiii iiii
    else if(myOpcode=="addi")
    {
    	//immediate 
    	myImmediate = bitset<16>(stoi(str4)).to_string();
        myRT = bitset< 5 >( stoi(str2)  ).to_string();
        myRS = bitset< 5 >( stoi(str3)  ).to_string();

    }
    //	slt $rd, $rs, $rt
    else if(myOpcode=="slt")
    {
    	myRD = bitset< 5 >( stoi(str2)  ).to_string();
        myRS = bitset< 5 >( stoi(str3)  ).to_string();
        myRT = bitset< 5 >( stoi(str4)  ).to_string();
    }
    //j target
    else if(myOpcode=="j")
    {

    	
    }
    //	sw $t, offset($s)
    else if(myOpcode=="sw")
    {
    	string offset = bitset< 16 >( stoi(str3)  ).to_string(); //offset
    	myImmediate = offset;

    	myRT = bitset< 5 >( stoi(str2)  ).to_string();
    	myRS = bitset< 5 >( stoi(str4)  ).to_string();

    }
    //lw $t, offset($s)
     else if(myOpcode=="lw")
    {
    	string offset = bitset< 16 >( stoi(str3)  ).to_string(); //offset
    	myImmediate = offset;

    	myRT = bitset< 5 >( stoi(str2)  ).to_string();
    	myRS = bitset< 5 >( stoi(str4)  ).to_string();
    	
    }
     else if(myOpcode=="beq")
    {
    	
    }



}
    
//get methods
string Instruction::getOpcode()
{
	return myOpcode;
}

string Instruction::getRS()
{
	return myRS;
}
string Instruction::getRD()
{
	return myRD;
}
string Instruction::getRT()
{
	return myRT;
}
string Instruction::getJumpAmount()
{
	return jumpTo;
}
string Instruction::getImmediate()
{
	return myImmediate;
}

    
//prints instructions
void Instruction::print()
{
 cout << part1 << " " << part2 << " "  << part3 << " "  << part4 << " "  << endl;
}
    
 string Instruction::instructionString()
 {
 	stringstream ss;
    ss << part1 << " " << part2 << " "  << part3 << " "  << part4 << " "  << endl;
    
    return ss.str();
 }

/*
Instruction::INS Instruction::getControlValues(){
  INS controlValues;

  //RTYPE 
  if((int)this-> myOpcode==000000){
    controlValues.RegDst="1";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="1";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  } else if((int)this-> myOpcode == 100011){
    controlValues.RegDst="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="1";
    controlValues.Regwrite="1";
    controlValues.MemRead="1";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }else if((int)this-> myOpcode == 101011){
    controlValues.RegDst="X";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="1";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }else if((int)this-> myOpcode == 000100){
    controlValues.RegDst="X";
    controlValues.ALUSrc="0";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="1";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="1";
    controlValues.Jump="0";
  }else if((int)this-> myOpcode == 001000){
    controlValues.RegDst="0";
    controlValues.ALUSrc="1";
    controlValues.MemtoReg="0";
    controlValues.Regwrite="1";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="0";
    controlValues.ALUOp0="0";
    controlValues.Jump="0";
  }
  //jump
  else if((int)this-> myOpcode == 000010){
    controlValues.RegDst="X";
    controlValues.ALUSrc="X";
    controlValues.MemtoReg="X";
    controlValues.Regwrite="0";
    controlValues.MemRead="0";
    controlValues.MemWrite="0";
    controlValues.Branch="0";
    controlValues.ALUOp1="X";
    controlValues.ALUOp0="X";
    controlValues.Jump="1";
  }

  return controlValues;
}
*/