#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "block.h"
#include "subject.h"
#include "levels.h"

using namespace std;

// class Block;
// struct Coord;

const int BOARD_HEIGHT = 18;
const int BOARD_WIDTH = 11;

class Board: public Subject {

  Block *theBlock;
  Level *theLevel; 
  int currentLevel = 0;

  int score = 0;

  vector<vector<char>> &matrix;
  unsigned int seed; //unsigned int required for rand function 

  string scriptFile; //used in the constructor  
  int startLevel;
  vector<string> &input; //vector for sequence files

 public:
  
  //explicit Board(vector<vector<char>> &matrix);
  explicit Board(vector<vector<char>> &matrix, unsigned int seed, string scriptFile, int startLevel);

  Block *&block() { return theBlock; }
  void levelup();
  void leveldown();
  void restart();
  void render();
  int getLevel();
  int getScore();
  char getState(int row, int col) const override;
  void drop();
  void lift();

  //for levels
  unsigned int getSeed();
  string getBlock();
  vector<string> &updateInputVector();

  ~Board();
};

#endif
