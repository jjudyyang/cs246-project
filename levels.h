#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"
#include "board.h"
#include <vector>
#include <string>

class Level{
    public:
        virtual Block* nextBlock(unsigned int seed, vector<string> &input) const = 0;
};
class Level0: public Level{
    Block* nextBlock(unsigned int seed, vector<string> &input) const override;
};
class Level1: public Level{
    Block* nextBlock(unsigned int seed, vector<string> &input) const override;
};
class Level2: public Level{
    Block* nextBlock(unsigned int seed, vector<string> &input) const override;
};
class Level3: public Level{
    Block* nextBlock(unsigned int seed, vector<string> &input) const override;
};
class Level4: public Level{
    Block* nextBlock(unsigned int seed, vector<string> &input) const override;
};

#endif