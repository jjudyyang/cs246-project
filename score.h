#ifndef SCORE_H
#define SCORE_H
#include "block.h"
#include "observer.h"

using namespace std;

class placedBlock {
    vector<Coord> squareList;
    int level;

    public:
        placedBlock(vector<Coord>& coords, int level);
        void deleteSquares(int line);
        bool isEmpty();
        int score();
};

class blockPile {
    vector<placedBlock> blockList;

    public:
        void addBlock(vector<Coord>& newCoords, int newLevel);
        int scoreLine(int line);
        int size() const;
};
#endif