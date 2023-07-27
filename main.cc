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

const int COLS = 11;
const int ROWS = 18;

//String of current commands
vector<string> validCommands = {
  "left",
  "right",
  "down",
  "clockwise",
  "counterclockwise",
  "drop",
  "levelup",
  "leveldown",
  "norandom",
  "random",
  "sequence",
  "restart",
  "hint"
};


int main ( int argc, char* argv[]) {

//---------------- process command line arguemnts ------------------

//Default Game Parameters 
  bool text = false; 
  unsigned int seed = 0;
  string scriptfile1 = "";
  string scriptfile2 = ""; 
  int startLevel = 0;

  //process Game Paramters
  processGameParameters(argc, argv, text, seed, scriptfile1, scriptfile2, startLevel);
  prettyPrintGameParameters(text, seed, scriptfile1, scriptfile2, startLevel);
  
  //create new command tree with given vector of commands
  TrieNode *commands = new TrieNode; 
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

//---------------- creating game pieces  ------------------

  //process input sequence vectors 
  vector<string> input1 = addInputSequenceToVector(scriptfile1);
  vector<string> input2 = addInputSequenceToVector(scriptfile2);

  //create board vector
  vector<vector<char>> matrix1(ROWS, vector<char>(COLS));
  vector<vector<char>> matrix2(ROWS, vector<char>(COLS));

  Board gameBoard1{matrix1, seed, scriptfile1, startLevel, input1 };
  Board gameBoard2{matrix2, seed, scriptfile2, startLevel, input2 };

  TextDisplay * ob = new TextDisplay(&gameBoard1, &gameBoard2);

  //---------------- TESTING ------------------

  I * iblock1 = new I;
  J * iblock2 = new J;

  gameBoard1.block() = iblock1; 
  gameBoard2.block() = iblock2;

  gameBoard1.attach(ob);
  gameBoard2.attach(ob);

  gameBoard1.render();
  gameBoard1.drop();
  gameBoard2.drop();
  gameBoard1.render();

  T * tblock1 = new T;
  O * oblock2 = new O;
  gameBoard1.block() = tblock1;
  gameBoard2.block() = oblock2;
  gameBoard1.render();
  gameBoard2.block()->setHeavy(4);
  for (int i = 0; i < 4; ++i) {
    gameBoard2.move("right");
    gameBoard1.render();
  }
  gameBoard1.drop();
  gameBoard1.render();
  // cout << "coords:" << endl;
  // vector<Coord> cList = gameBoard2.block()->blockCoords();
  // for (Coord square : cList) {
  //   cout << "x: " << square.x << "y: " << square.y;
  // }
  //---------------- begin of game logic ------------------
  
  cout<<"begin inputing commands"<<endl;

  string input;
  while( getline (cin, input) ){

    //MOVE ELSE WHERE
    //convert input to stream for mutiple commands 
    stringstream ss{input};
    vector<string> commandsVector;
    string temp;
    while( ss >> temp){
      commandsVector.push_back(temp);
    }
    for(int i = 0; i < commandsVector.size(); ++i){
      string command = commandsVector[i];
      auto result = seperateStringFromInt(command);
      string fullCommand = commands->search(result.second);

      cout<<"full command: "<<fullCommand<<endl; //this is feedback for the command

        //update score 
        //render board from the commands
        //ie  clear lines, display score 

        //special actions 
        //if speical actions happen, render board again  

    }

  //deallocate commands
  delete commands; 
  }
}