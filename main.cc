#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "functions.h"
#include "block.h"
#include "board.h"
#include "levels.h"
#include "textdisplay.h"
#include "commandInterpreter.h"

using namespace std;

int main ( int argc, char* argv[]) {

 //---------------- TESTING ------------------

  // I * iblock1 = new I;
  // J * iblock2 = new J;

  // gameBoard1.block() = iblock1; 
  // gameBoard2.block() = iblock2;

  // gameBoard1.attach(ob);
  // gameBoard2.attach(ob);

  // gameBoard1.render();
  // gameBoard1.drop();
  // gameBoard2.drop();
  // gameBoard1.render();

  // T * tblock1 = new T;
  // O * oblock2 = new O;
  // gameBoard1.block() = tblock1;
  // gameBoard2.block() = oblock2;
  // gameBoard1.render();
  // gameBoard2.block()->setHeavy(4);
  // for (int i = 0; i < 4; ++i) {
  //   gameBoard2.move("right");
  //   gameBoard1.render();
  // }
  // gameBoard1.drop();
  // gameBoard1.render();

  // cout << "coords:" << endl;
  // vector<Coord> cList = gameBoard2.block()->blockCoords();
  // for (Coord square : cList) {
  //   cout << "x: " << square.x << "y: " << square.y;
  // }

  gameController( argc, argv );

  }