#ifndef DECORATOR_H
#define DECORATOR_H
#include "block.h"

class Decorator : public Block {
 protected:
    Block * component;
 public:
    Decorator(Block * p);
    virtual ~Decorator();
};

#endif

