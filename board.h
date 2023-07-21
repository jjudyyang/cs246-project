#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "subject.h"

using namespace std;

class Block;

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

  ~Board();
};

#endif
