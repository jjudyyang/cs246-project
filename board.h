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

class Level; // Forward declaration of the Level class
//^^ tells compiler that levels exist without providing full defination

const int BOARD_HEIGHT = 18;
const int BOARD_WIDTH = 11;

class Board: public Subject {

  public: //! this might be problem 
  Block *theBlock;
  Level *theLevel; 
  int currentLevel = 0;

  int score = 0;

  vector<vector<char>> &matrix;
  unsigned int seed; //unsigned int required for rand() function 

  string scriptFile; //used in the constructor  
  int startLevel; //TODO, COMBINE WITH OTHER LEVEL VARIABLE TO REMOVE DEPENDANCY
  vector<string> &input; //vector for sequence files

 public:
  
  //explicit Board(vector<vector<char>> &matrix);
  explicit Board(vector<vector<char>> &matrix, unsigned int seed, string scriptFile, int startLevel, vector<string> &input);

  Block *&block() { return theBlock; } //copy ctor
  void levelup();
  void leveldown();
  void restart();
  void render();
  int getLevel();
  int getScore();
  char getState(int row, int col) const override;
  void lift();

  void drop();
  bool validCoords(const vector<Coord> coordList) const;
  bool move(string movement);

  //for levels
  unsigned int getSeed();
  string getBlock();
  void updateInputVector();
};

#endif