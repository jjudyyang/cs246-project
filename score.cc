#include "score.h"

placedBlock::placedBlock(Vector<Coord> coords, int level):
    squareList{coords}, level{level} {}

void placedBlock::deleteSquares(int line) {
    for (Coord square : squareList) {
        if (square.y == line) {
            squareList.erase(square);
        }
    }
}

bool placedBlock::isEmpty() {
    return squareList.empty();
}

int placedBlock::score() {
    return (level + 1) * (level + 1);
}

void blockPile::addBlock(Vector<Coord> newCoords, int newlevel) {
    blockList.emplace_back(newCoords, newLevel);
}

int blockPile::scoreLine(int line) {
    int sum = 0;
    for (placedBlock pb : blockList) {
        pb.deleteSquares();
        if (pb.isEmpty()) {
            sum += pb.score();
            blockList.erase(pb);
        }
    }
    return sum;
}