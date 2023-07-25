#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"
#include "board.h"
#include <vector>

class Level{

    protected:
        Board *theBoard;
        
    public:
        virtual Block* nextBlock() const = 0;
        mutable vector<string> input;

        //function to create vector of blocks to generate
        //must run once
        void addToInputSequence(vector<string> &input);
};
class Level0: public Level{
    Block* nextBlock() const override;
};
class Level1: public Level{
    Block* nextBlock() const override;
};
class Level2: public Level{
    Block* nextBlock() const override;
};
class Level3: public Level{
    Block* nextBlock() const override;
};
class Level4: public Level{
    Block* nextBlock() const override;
};


#endif



