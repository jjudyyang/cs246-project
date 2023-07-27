#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"
#include "board.h"
#include <vector>

class Board;
//^forwarding dependancies 

class Level{
    protected: // can be accessed by derived classes
        Board *theBoard; 
    public:
        virtual Block* nextBlock() const = 0;
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