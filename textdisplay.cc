#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board *board1, Board *board2): 
board1{board1}, board2{board2} {}

TextDisplay::~TextDisplay() {
    board1->detach(this);
    board2->detach(this);
}

void TextDisplay::notify() {
    vector<Coord> tetrominos1 = board1->block()->blockCoords();
    vector<Coord> tetrominos2 = board2->block()->blockCoords();
    cout << "Level: " << board1->getLevel();
    cout << "        ";
    cout << "Level: " << board2->getLevel() << endl;
    cout << "Score: " << board1->getScore();
    cout << "        ";
    cout << "Score: " << board2->getScore() << endl;
    for (int col = 0; col < 11; col++) {
        cout << "-";
    }

    for (int i = 0; i < 5; i++) {
        cout << " ";
    }

    for (int col = 0; col < 11; col++) {
        cout << "-";
    }

    cout << endl;

    for (int row = 0; row < 18; row++) {
        for (int col = 0; col < 11; col++) {
            if (row == tetrominos1[0].y && col == tetrominos1[0].x) {
                cout << board1->block()->blockType();
            } else if (row == tetrominos1[1].y && col == tetrominos1[1].x) {
                cout << board1->block()->blockType();
            } else if (row == tetrominos1[2].y && col == tetrominos1[2].x) {
                cout << board1->block()->blockType();
            } else if (row == tetrominos1[3].y && col == tetrominos1[3].x) {
                cout << board1->block()->blockType();
            } else {
                cout << board1->getState(row, col);
            }
        }

        for (int i = 0; i < 5; i++) {
            cout << " ";
        }

        for (int col = 0; col < 11; col++) {
            if (row == tetrominos2[0].y && col == tetrominos2[0].x) {
                cout << board2->block()->blockType();
            } else if (row == tetrominos2[1].y && col == tetrominos2[1].x) {
                cout << board2->block()->blockType();
            } else if (row == tetrominos2[2].y && col == tetrominos2[2].x) {
                cout << board2->block()->blockType();
            } else if (row == tetrominos2[3].y && col == tetrominos2[3].x) {
                cout << board2->block()->blockType();
            } else {
                cout << board2->getState(row, col);
            }
        }

        cout << endl;
    }

    for (int col = 0; col < 11; col++) {
        cout << "-";
    }

    for (int i = 0; i < 5; i++) {
        cout << " ";
    }

    for (int col = 0; col < 11; col++) {
        cout << "-";
    }

    cout << endl;
}
