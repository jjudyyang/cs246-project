#include "block.h"
#include "board.h"

using namespace std;

Block::Block(): pos{Coord{0, 3}}, orientation{0}, heavy{0} {}

void Block::rotateClockwise() {
    ++orientation;
    orientation %= 4;
}

void Block::rotateCounterClockwise() {
    --orientation;
    orientation %= 4;
}

void Block::moveLeft() {
    if (pos.x <= 0) {
        return;
    }
    --pos.x;
    for (int i = 0; i < heavy; i++) {
        moveDown();
    }
}

void Block::moveRight() {
    if (pos.x >= BOARD_WIDTH - 1) {
        return;
    }
    ++pos.x;
    for (int i = 0; i < heavy; i++) {
        moveDown();
    }
}

void Block::moveDown() {
    if (pos.y >= BOARD_HEIGHT - 1) {
        return;
    }
    ++pos.y;
}

char I::blockType() const {
    return blockChar;
}

vector<Coord> I::blockCoords() const {
    vector<Coord> retvec;
    if (orientation % 2 == 0) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, 0});
        retvec.emplace_back(Coord{3, 0});
    } else {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{0, -3});
    }
    for (Coord square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}