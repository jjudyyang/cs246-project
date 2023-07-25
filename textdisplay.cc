#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board *board1, Board *board2): 
board1{board1}, board2{board2} {}

TextDisplay::~TextDisplay() {
    board1->detach(this);
    board2->detach(this);
}

void TextDisplay::notify() {
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
            cout << board1->getState(row, col);
        }

        for (int i = 0; i < 5; i++) {
        cout << " ";
        }

        for (int col = 0; col < 11; col++) {
            cout << board2->getState(row, col);
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
