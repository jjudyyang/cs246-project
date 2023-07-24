#include "board.h"
#include "block.h"
#include <vector>

Board::Board( vector<vector<char>> matrix): matrix{matrix} {}

Board::~Board() {}

void Board::levelup() {
    return;
}

void Board::leveldown() {
    return;
}

void Board::restart() {
    for (int row = 0; row < 15; row++) {
        for (int col = 0; col < 11; col++) {
            matrix[row][col] = ' ';
        }
    }
}

void Board::render() {
    notifyObservers();
}

int Board::getLevel() {
    return level;
}

int Board::getScore() {
    return score;
}

char Board::getState(int row, int col) const {
    return matrix[row][col];
}

void Board::drop() {
    vector<Coord> block = theBlock->blockCoords();
    for (Coord blockPos : block) {
        matrix[blockPos.x][blockPos.y] = theBlock->blockType();
    }
}