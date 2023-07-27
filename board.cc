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
    while (move("down")) {

    }
}

bool Board::validCoords(const vector<Coord> coordList) const {
    for (Coord square : coordList) {
        if (square.x < 0 || square.x >= BOARD_WIDTH) {
            return false;
        } else if (square.y < 0 || square.y >= BOARD_HEIGHT) {
            return false;
        } else if (matrix[square.y][square.x] != ' ') {
            return false;
        } else {
            return true;
        }
    }
}

bool Board::move(string movement) {
    if (movement == "down") {
        
    }
}