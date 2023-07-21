#include "board.h"
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
    return;
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