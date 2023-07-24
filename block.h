#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>

using namespace std;

struct Coord {
   int x;
   int y;
};


class Block {
 protected:
   struct Coord pos;
   int orientation;    // 0 default, -1 for 90 deg ccw turn, +1 cw turn
   int heavy;
 public:
   Block();
   void rotateClockwise();
   void rotateCounterClockwise();
   void moveLeft();
   void moveRight();
   void moveDown();
   virtual char blockType() const = 0;
   virtual vector<Coord> blockCoords() const = 0;
};

class I : public Block {
   const char blockChar = 'I';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

#endif