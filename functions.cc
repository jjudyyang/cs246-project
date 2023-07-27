#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "functions.h"
#include "block.h"
#include "board.h"
#include "levels.h"
#include "textdisplay.h"
#include "commandInterpreter.h"

class Board;
class Level;

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

pair<int, string> seperateStringFromInt (const string &input){
  stringstream ss(input);
  string str;
  int num;
  ss >> num;
  if( ss.fail() ){
    num = 0;
    str = input;
  }else{
    getline(ss >> ws, str);
  }
  return make_pair(num, str);
}

void prettyPrintGameParameters(bool text, unsigned int seed, string scriptfile1, string scriptfile2, int startlevel){
    
    cout << "------ Game Parameters: ------\n";
    cout << "Text Mode Only: " << (text ? "YES" : "NO") << "\n";
    cout << "Seed: " << seed << "\n";
    cout << "Script File 1: " << scriptfile1 << "\n";
    cout << "Script File 2: " << scriptfile2 << "\n";
    cout << "Start Level: " << startlevel << "\n";
    cout << "-------------------------------"<<endl;
    cout << endl;
}

void processGameParameters(int argc, char*argv[], bool &text, unsigned int &seed, string &scriptfile1, string &scriptfile2, int &startlevel){

    for(int i = 1; i < argc; ++i){ //skip executable
    string command = argv[i];
    if(command == "text"){
      text = true;
    }else if(command == "seed"){
      ++i;
      seed = stoi(argv[i]);
    }else if(command == "scriptfile1"){
      ++i;
      scriptfile1 = argv[i]; 
    }else if(command == "scriptfile2"){
      ++i;
      scriptfile2 = argv[i]; 
    }else if(command == "startlevel"){
      ++i;
      startlevel = stoi(argv[i]);
    }
  }

}

vector<string> addInputSequenceToVector( string scriptfile){

  //add script file to vector (for level 0)
  vector<string> input;
    if(scriptfile != ""){
        ifstream MyFile{scriptfile};
        string s;
        while ( getline(MyFile, s) ){
            cout<<"s: "<<s<<endl;
            input.push_back(s);
        }
    }else{
        cout<<"missing script file"<<endl;
    }
    return input;
}

void setLevel(Board &board, int level){
  if(level == 0){
    board.theLevel = new Level0;
  }else if(level == 1){
    board.theLevel = new Level1;
  }else if (level == 2){
    board.theLevel = new Level2;
  }else if (level == 3){
    board.theLevel = new Level3;
  }else{
    cout<<"level 4 under construction"<<endl;
  }
}

//main game controller 
void gameController( int argc, char* argv[] ){

  //Default Game Parameters 
  bool text = false; 
  unsigned int seed = 0;
  string scriptfile1 = "";
  string scriptfile2 = ""; 
  int startLevel = 0;

  //process Game Paramters
  processGameParameters(argc, argv, text, seed, scriptfile1, scriptfile2, startLevel);
  prettyPrintGameParameters(text, seed, scriptfile1, scriptfile2, startLevel);

  //process input sequence vectors 
  vector<string> input1 = addInputSequenceToVector(scriptfile1);
  vector<string> input2 = addInputSequenceToVector(scriptfile2);

  //create board vector and board
  vector<vector<char>> matrix1(ROWS, vector<char>(COLS));
  vector<vector<char>> matrix2(ROWS, vector<char>(COLS));
  Board gameBoard1{matrix1, seed, scriptfile1, startLevel, input1 };
  Board gameBoard2{matrix2, seed, scriptfile2, startLevel, input2 };

  //display
  TextDisplay * ob = new TextDisplay(&gameBoard1, &gameBoard2);

  //create new command tree with given vector of commands
  TrieNode *commands = new TrieNode; 
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

//adding first block to board based on level
setLevel(gameBoard1, gameBoard1.getLevel()); 
setLevel(gameBoard2, gameBoard2.getLevel());

  gameBoard1.block() = gameBoard1.theLevel->nextBlock();
  gameBoard2.block() = gameBoard2.theLevel->nextBlock();
  gameBoard1.attach(ob); 
  gameBoard2.attach(ob);

  gameBoard1.render(); //renders empty board

  cout<<"begin inputting commands!"<<endl;
  
  int currentPlayer = 0;
  string input;
  while( getline (cin, input) ){

      auto result = seperateStringFromInt(input);
      string fullCommand = commands->search(result.second);
      cout<<"input: "<<fullCommand<<endl; //this is feedback for the command

      if(fullCommand != "ERROR: command does not exist" && fullCommand != "MUTIPLE"){
        //valid command, process the command
        if(currentPlayer % 2 == 0){
          processCommand(gameBoard1, fullCommand); 
        }else{
          processCommand(gameBoard2, fullCommand); 
        }

        if(fullCommand == "drop"){
          //generate block for next board
          if(currentPlayer % 2 == 0){
            gameBoard1.block() = gameBoard1.theLevel->nextBlock();
          }else{
            gameBoard2.block() = gameBoard2.theLevel->nextBlock();
          }
          //switch players 
          currentPlayer++;
        }
        gameBoard1.render(); //only render after sucessfull command
      }
  }

  delete commands;
}

void processCommand(Board &board, string c){
  //thanks david for writing move :-)
  if( c == "left" ){
    board.move("left");
  }else if( c == "right"){
    board.move("right");
  }else if( c == "down"){
    board.move("down");
  }else if( c == "clockwise"){
    board.move("clockwise");
  }else if( c == "counterclockwise"){
    board.move("counterclockwise");
  }else if( c == "drop"){
    board.drop();
  }else if( c == "levelup" ){
    board.levelup();
  }else if( c == "leveldown"){
    board.leveldown();
  }
  else if( c == "down" ){
    board.move("down");
  }else if( c == "norandom"){
    
  }else if( c == "random"){
    
  }else if( c == "sequence"){
    
  }else if( c == "restart"){

  }else if( c == "hint"){

  }else{
    cout<<"quit command loop"<<endl;
  }

}