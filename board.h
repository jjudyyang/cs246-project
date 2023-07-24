#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "subject.h"

class Block;

const int BOARD_HEIGHT = 18;
const int BOARD_WIDTH = 11;

class Board: public Subject {
  Block *theBlock;
  int level = 0;
 public:
  explicit Board(Block *block): theBlock{block} {}

  Block *&block() { return theBlock; }
  void levelup();
  void leveldown();
  void restart();
  void render();
  char getState(int row, int col) const override;
  
  ~Board();
};

#endif
