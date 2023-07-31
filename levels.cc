#include "levels.h"
#include "board.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

//force block 
Block* Level::nextBlock(string block){
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

Block* Level0::nextBlock(vector<string> &input) const{
    
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

//S and Z are selected with 1/12 
//remaining are selected with 1/6
Block* Level1::nextBlock(vector<string> &input) const{
    
    int random = rand() % 6;

    if(random == 0){
        I * nextBlock = new I;
        return nextBlock;  
    } else if (random == 1 ){
        J * nextBlock = new J;
        return nextBlock;  
    } else if (random == 2 ){
        L * nextBlock = new L;
        return nextBlock;  
    } else if (random == 3 ){
        O * nextBlock = new O;
        return nextBlock;  
    } else if (random == 4 ){
        T * nextBlock = new T;
        return nextBlock;  
    } else if (random == 5 ){
        //choose between S and Z
        random = rand() % 2;
        if(random == 0){
            S * nextBlock = new S;
            return nextBlock;  
        }else{
            Z * nextBlock = new Z;
            return nextBlock;  
        }
    }
}

//all blocks selected with equal probability 
Block* Level2::nextBlock(vector<string> &input) const{
    
    int random = rand() % 7;

    if(random == 0){
        I * nextBlock = new I;
        return nextBlock;  
    } else if (random == 1 ){
        J * nextBlock = new J;
        return nextBlock;  
    } else if (random == 2 ){
        L * nextBlock = new L;
        return nextBlock;  
    } else if (random == 3 ){
        O * nextBlock = new O;
        return nextBlock;  
    } else if (random == 4 ){
        T * nextBlock = new T;
        return nextBlock;  
    } else if (random == 5 ){
        S * nextBlock = new S;
        return nextBlock; 
    } else if (random == 6 ){
        Z * nextBlock = new Z;
        return nextBlock; 
    }
}

Block* Level3::nextBlock(vector<string> &input) const{
    //need to set next block to is heavy
    int random = rand() % 9;
    if(random == 0){
        I * nextBlock = new I;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 1 ){
        J * nextBlock = new J;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 2 ){
        L * nextBlock = new L;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 3 ){
        O * nextBlock = new O;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 4 ){
        T * nextBlock = new T;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 5 || random == 7 ){
        S * nextBlock = new S; // 2/9
        nextBlock->setHeavy(1);
        return nextBlock; 
    } else if (random == 6 || random == 8){
        Z * nextBlock = new Z; // 2/9
        nextBlock->setHeavy(1);
        return nextBlock; 
    } 
}

Block* Level4::nextBlock(vector<string> &input) const{

    //TODO
    //if mutiples of 5 blocks places without clearing
    //1x1 (*) is placed in the center of the board 

    int random = rand() % 9;
    if(random == 0){
        I * nextBlock = new I;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 1 ){
        J * nextBlock = new J;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 2 ){
        L * nextBlock = new L;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 3 ){
        O * nextBlock = new O;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 4 ){
        T * nextBlock = new T;
        nextBlock->setHeavy(1);
        return nextBlock;  
    } else if (random == 5 || random == 7 ){
        S * nextBlock = new S; // 2/9
        nextBlock->setHeavy(1);
        return nextBlock; 
    } else if (random == 6 || random == 8){
        Z * nextBlock = new Z; // 2/9
        nextBlock->setHeavy(1);
        return nextBlock; 
    }

}


