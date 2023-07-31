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
  "restart"
};
//note: tri node does not work with single letters 

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

vector<string> addInputSequenceToVector( string scriptfile ){

  //add script file to vector (for level 0)
  vector<string> input;
    if(scriptfile != ""){
        ifstream MyFile{scriptfile};
        string s;
        while ( getline(MyFile, s) ){
            stringstream letter{s};
            string blockLetter;
            while(letter >> blockLetter){
              //cout<<"s: "<<blockLetter<<endl;
              input.push_back(blockLetter);
            }
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

//do the prefixing
void multiplierPrefix(int prefix, Board &board, string command){
  if(prefix != 0){
    for(int i = 0; i < prefix; i++){
      processCommand(board, command); 
    }
  }else{
    processCommand(board, command); 
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

  for(int i = 0; i < input1.size(); i++){
    cout<<input1[i]<<" ";
  }
  cout<<endl;
  for(int i = 0; i < input2.size(); i++){
    cout<<input2[i]<<" ";
  }
  cout<<endl;

  //create board vector and board
  vector<vector<char>> matrix1(ROWS, vector<char>(COLS));
  vector<vector<char>> matrix2(ROWS, vector<char>(COLS));

  restart:
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

  gameBoard1.block() = gameBoard1.theLevel->nextBlock(input1);
  gameBoard2.block() = gameBoard2.theLevel->nextBlock(input2);
  gameBoard1.attach(ob); 
  gameBoard2.attach(ob);

  gameBoard1.render(); //renders empty board
  cout<<"begin inputting commands!"<<endl;
  
  int currentPlayer = 0;
  string input;

  ifstream sequenceFile;
  sequence:

  while( getline (cin, input) ){

      auto result = seperateStringFromInt(input);
      string fullCommand = commands->search(result.second);
      int prefix = result.first;
      
      //command interpreters response
      cout<<"prefix: "<<prefix<<endl;
      cout<<"input: "<<fullCommand<<endl; 

      if (fullCommand == "restart"){
        goto restart;
      }
      if(fullCommand == "norandom"){ //make both boards take input from one file
        cout<<"";
      }
      if(fullCommand == "random"){ //toggle the randomness off

      }
      if(fullCommand == "sequence"){
        string fileName;
        cout<<"enter sequence file to execute commands from: "; 
        cin>>fileName;
        sequenceFile.open(fileName.c_str());
        if (!sequenceFile.is_open())
          cout << "Failed to open the file." << endl;
        
        cin.rdbuf(sequenceFile.rdbuf());//change cin to read from this file
        goto sequence; //go to start of while loop to read file
      }

      //helper function to process commands
      if(fullCommand != "ERROR: command does not exist" && fullCommand != "MUTIPLE"){
          //valid move command
          if(currentPlayer % 2 == 0){ //player1
            multiplierPrefix(prefix, gameBoard1, fullCommand);
          }else{ //player2
            multiplierPrefix(prefix, gameBoard2, fullCommand); 
          }

        //check if block was dropped
        if(fullCommand == "drop"){ //generate block for next board
          if(currentPlayer % 2 == 0){
            gameBoard1.block() = gameBoard1.theLevel->nextBlock(input1);
          }else{
            gameBoard2.block() = gameBoard2.theLevel->nextBlock(input2);
          }
          currentPlayer++; //switch players 
          // if special actions triggered
          if( false ){ //condition: two or more lines cleared
            specialAction (currentPlayer, gameBoard1, gameBoard2);
          }
        }

        gameBoard1.render(); //only render after sucessful command
      }
  }

  delete commands;
}

void specialAction (int currentPlayer, Board &gameBoard1, Board &gameBoard2){
  gameBoard1.render(); //renders the drop
  int selection;
  string forceBlock;
  cout<<"*** Special Actions Trigger ***"<<endl;
  cout<<"select from the following: "<<endl;
  cout<<"1: blind"<<endl<<"2: heavy"<<endl<<"3: force"<<endl;
  cin>>selection;

  if(selection == 3){
    cout<<"Enter block to drop (I, J, L, O, Z, T, S): ";
    cin>>forceBlock;
  }

  //execute the commands
  if(selection == 1){
              
  }
  else if(selection == 2){
    if(currentPlayer % 2 == 0) gameBoard1.block()->setHeavy(2);
    else gameBoard2.block()->setHeavy(2);
  }
  else if(selection == 3){
    if(currentPlayer % 2 == 0) gameBoard1.block() = gameBoard1.theLevel->nextBlock(forceBlock);
    else gameBoard2.block() = gameBoard2.theLevel->nextBlock(forceBlock);
  }
  else{
    cout<<"invalid command"<<endl;
  }
}

void processCommand(Board &board, string c){
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
  }else{
    cout<<"quit command loop"<<endl; //should not get to here
  }
}