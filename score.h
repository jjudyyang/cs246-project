#include "block.cc"
#include "observer.h"

class placedBlock() {
    vector<vector<Coord>> squareList;
    int level;

    public:
        placedBlock(Vector<Coord> coords, int level);
        int deleteSquares(int line);
        bool isEmpty();
        int score();
};

class blockPile () {
    vector<placedBlock> blockList;

    public:
        void addBlock(Vector<Coord> newCoords, int newlevel);
        int scoreLine(int line);
};