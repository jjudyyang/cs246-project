#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <block.h>
#include "subject.h"

using namespace std;

class Block;
struct Coord;

const int BOARD_HEIGHT = 18;
const int BOARD_WIDTH = 11;

class Board: public Subject {
  Block *theBlock;
  int level = 0;
  int score = 0;
  vector<vector<char>> matrix;
 public:
  explicit Board(vector<vector<char>> matrix);

  Block *&block() { return theBlock; }
  void levelup();
  void leveldown();
  void restart();
  void render();
  int getLevel();
  int getScore();
  char getState(int row, int col) const override;
  void drop();

  ~Board();
};

#endif
