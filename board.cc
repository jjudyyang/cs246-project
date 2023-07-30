#include "board.h"
#include "block.h"
#include "levels.h"
#include <vector>
#include <fstream>
#include <string>

Board::Board(vector<vector<char>> &matrix, unsigned int seed, string scriptFile, int startLevel, vector<string> &input): 
    matrix{matrix}, pile{make_unique<blockPile>()}, seed{seed}, scriptFile{scriptFile}, startLevel{startLevel}, input{input} {

    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            matrix[row][col] = ' ';
        }
    }

    //update current level
    currentLevel = startLevel; 

    //update pointer to start level (intially constructed with start level)
    switch(startLevel){
        case 0:
            theLevel = new Level0;
            break;
        case 1:
            theLevel = new Level1;
            break;
        case 2:
            theLevel = new Level2;
            break;
        case 3:
            theLevel = new Level3;
            break;
        case 4:
            theLevel = new Level4;
            break;
    }

}

void Board::levelup() {
    //check range
    if(currentLevel == 4){
        cout<<"MAX Level Reached"<<endl;
    }
    else{
        ++currentLevel; //update new level 
        switch(currentLevel){
            case 1:
                theLevel = new Level1; 
                break;
            case 2:
                theLevel = new Level2;
                break;
            case 3:
                theLevel = new Level3;
                break;
            case 4:
                theLevel = new Level4;
                break;
        }
    }
    return;
}

void Board::leveldown() {
    //check range
    if(currentLevel == 0){
        cout<<"MIN Level Reached"<<endl;
    }
    else{
        --currentLevel; //update new level 
        switch(currentLevel){
            case 0:
                theLevel = new Level0; 
                break;
            case 1:
                theLevel = new Level1;
                break;
            case 2:
                theLevel = new Level2;
                break;
            case 3:
                theLevel = new Level3;
                break;
        }
    }
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
    return currentLevel;
}

int Board::getScore() {
    return score;
}

char Board::getState(int row, int col) const {
    return matrix[row][col];
}

void Board::drop() {
    while (move("down")) {}
    vector<Coord> squares = theBlock->blockCoords();
    vector<Coord> &squareRef = squares;
    char type = theBlock->blockType();
    for (Coord square : squareRef) {
        matrix[square.y][square.x] = type;
    }
    pile->addBlock(squareRef, theBlock->getLevel());
}

bool Board::validCoords(const vector<Coord> coordList) const {
    for (Coord square : coordList) {
        //cout << "\nx: " << square.x << "y: " << square.y << endl;
        if (square.x < 0 || square.x >= BOARD_WIDTH) {
            return false;
        } else if (square.y < 0 || square.y >= BOARD_HEIGHT) {
            return false;
        } else if (matrix[square.y][square.x] != ' ') {
            return false;
        }
    }
    return true;
}

// returns false if movement is not a valid command or if the movement results 
//   in an intersection with another block (no change to block done in this case)
bool Board::move(string movement) {
    // may want to change implementation to use a virtual copy constructor instead
    //   of changing fields (reduces coupling)
    Coord tempPos = theBlock->getPos();
    int tempOri = theBlock->getOrientation();
    int heaviness = theBlock->getHeavy();

    if (movement == "down") {
        theBlock->moveDown();
    } else if (movement == "left") {
        theBlock->moveLeft();
        for (int i = 0; i < heaviness; ++i) {
            move("down");
        }
    } else if (movement == "right") {
        theBlock->moveRight();
        for (int i = 0; i < heaviness; ++i) {
            move("down");
        }
    } else if (movement == "clockwise") {
        theBlock->rotateClockwise();
    } else if (movement == "counterclockwise") {
        theBlock->rotateCounterClockwise();
    } else {
        return false;
    }

    if (validCoords(theBlock->blockCoords())) {
        return true;
    }

    // revert movement if coordinates become invalid
    theBlock->setPos(tempPos);
    theBlock->setOrientation(tempOri);
    return false;
}

// levels accessor methods 
unsigned int Board::getSeed(){
    return seed;
} 
string Board::getBlock(){
    return input[0]; // return the top 
}
void Board::updateInputVector(){
    string top = input[0]; // save top
    input.erase(input.begin()); //remove top
    input.push_back(top); // add top to back
}

int Board::lineScore() const {
    return (currentLevel + 1) * (currentLevel + 1);
}

// clears all filled lines and updates score accordingly
bool Board::clearFullLines() {
    bool lineCleared = false;
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        bool lineFull = true;
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (matrix[i][j] == ' ') {
                lineFull = false;
                break;
            }
        }
        if (lineFull) {
            score += pile->scoreLine(i);
            score += lineScore();
            matrix.erase(matrix.begin() + i);
            vector<char> emptyLine(BOARD_WIDTH, ' ');
            matrix.insert(matrix.begin(), emptyLine);
            lineCleared = true;
        }
    }
    return lineCleared;
}