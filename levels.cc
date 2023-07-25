#include "levels.h"
#include "board.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>



void Level::addToInputSequence(vector<string> &input){
    string input = theBoard->getInputSequence();
    ifstream MyFile{input};
    string s;
    while ( getline(MyFile, s) ){
        input.push_back(s);
    }
}


Block* Level0::nextBlock() const{
    string block = input[0];
    input.erase(input.begin());
    input.push_back(block);

    if(block == "I"){
        I * nextBlock = new I;
        return nextBlock;  
    }else if(block == "J" ){
        J * nextBlock = new J;
        return nextBlock;  
    }else if(block == "L" ){
        L * nextBlock = new L;
        return nextBlock;  
    }else if(block == "O" ){
        O * nextBlock = new O;
        return nextBlock;  
    }else if(block == "Z" ){
        Z * nextBlock = new Z;
        return nextBlock;  
    }else if(block == "T" ){
        T * nextBlock = new T;
        return nextBlock;  
    }else if(block == "S" ){
        S * nextBlock = new S;
        return nextBlock;  
    }

}
Block* Level1::nextBlock() const{
    
}

Block* Level2::nextBlock() const{
    
}

Block* Level3::nextBlock() const{
    
}
Block* Level4::nextBlock() const{
    
}

