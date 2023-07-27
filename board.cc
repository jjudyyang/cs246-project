#include "board.h"
#include "block.h"
#include "levels.h"
#include <vector>
#include <fstream>
#include <string>

Board::Board(vector<vector<char>> &matrix, unsigned int seed, string scriptFile, int startLevel, vector<string> &input): matrix{matrix}, seed{seed}, scriptFile{scriptFile}, startLevel{startLevel}, input{input} {

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

Board::~Board() {}

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
    return true; //for testing
}

bool Board::move(string movement) {
    // if (movement == "down") {
        
    // }
    return true; //for testing
}

// levels accessor methods 
unsigned int Board::getSeed(){
    return seed;
} 
string Board::getBlock(){
    return input[0]; // return the top 
}
vector<string>& Board::updateInputVector(){
    string top = input[0]; // save top
    input.erase(input.begin()); //remove top
    input.push_back(top); // add top to back
}
