#include "score.h"

using namespace std;

placedBlock::placedBlock(vector<Coord>& coords, int level):
    squareList{coords}, level{level} {}

void placedBlock::deleteSquares(int line) {
    for (size_t i = 0; i < squareList.size(); ++i) {
        if (squareList[i].y == line) {
            squareList.erase(squareList.begin() + i);
        }
    }
}

bool placedBlock::isEmpty() {
    return squareList.empty();
}

int placedBlock::score() {
    return (level + 1) * (level + 1);
}

void blockPile::addBlock(vector<Coord>& newCoords, int newLevel) {
    placedBlock newPlaced{newCoords, newLevel};
    blockList.push_back(newPlaced);
}

int blockPile::scoreLine(int line) {
    int sum = 0;
    for (size_t i = 0; i < blockList.size(); ++i) {
        blockList[i].deleteSquares(line);
        if (blockList[i].isEmpty()) {
            sum += blockList[i].score();
            blockList.erase(blockList.begin() + i);
        }
    }
    return sum;
}

int blockPile::size() const {
    return blockList.size();
}