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
      int level;
   public:
      Block(int level = 0);
      Block(const Block &other);
      void rotateClockwise();
      void rotateCounterClockwise();
      void moveLeft();
      void moveRight();
      void moveDown();
      void moveUp();
      virtual char blockType() const = 0;
      virtual vector<Coord> blockCoords() const = 0;
      Coord getPos() const;
      void setPos(Coord newPos);
      int getOrientation() const;
      void setOrientation(int newOri);
      int getHeavy() const;
      void setHeavy(int newHeaviness);
      int getLevel() const;
      void setLevel(int newLevel);
};

class I : public Block {
   const char blockChar = 'I';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class J : public Block {
   const char blockChar = 'J';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class L : public Block {
   const char blockChar = 'L';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class O : public Block {
   const char blockChar = 'O';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class S : public Block {
   const char blockChar = 'S';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class Z : public Block {
   const char blockChar = 'Z';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

class T : public Block {
   const char blockChar = 'T';
   public:
      char blockType() const override;
      vector<Coord> blockCoords() const override;
};

#endif