#ifndef TDISPLAY_H
#define TDISPLAY_H
#include "observer.h"
#include "board.h"
#include "block.h"

class TextDisplay: public Observer {
    Board * board1;
    Board * board2;
 public:
    TextDisplay(Board *board1, Board *board2);
    ~TextDisplay();
    void notify() override;
};

#endif
