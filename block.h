#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>

class Block {
    int pos_x;
    int pos_y;
    int orientation;
 public:
   virtual ~Block();
   virtual void rotateClockwise() = 0;
   virtual void rotateCounterClockwise() = 0;
   virtual void moveLeft() = 0;
   virtual void moveRight() = 0;
};

#endif
