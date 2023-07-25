#include "board.h"
#include "block.h"
#include <vector>

Board::Board(vector<vector<char>> &matrix): matrix{matrix} {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            matrix[row][col] = ' ';
        }
    }
}

Board::~Board() {}

void Board::levelup() {
    return;
}

void Board::leveldown() {
    return;
}

void Board::restart() {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
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
    vector<Coord> blockSquares = theBlock->blockCoords();
    for (Coord blockPos : blockSquares) {
        cout << "x: " << blockPos.x << endl;
        cout << "y: " << blockPos.y << endl;
        matrix[blockPos.y][blockPos.x] = theBlock->blockType();
    }
}

void Board::lift() {
    vector<Coord> blockSquares = theBlock->blockCoords();
    for (Coord blockPos : blockSquares) {
        matrix[blockPos.y][blockPos.x] = ' ';
    }
}