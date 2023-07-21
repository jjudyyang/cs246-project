#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "board.h"
#include "blank.h"
#include "textdisplay.h"
#include "commandInterpreter.h"

using namespace std;

// String of current commands
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

int main () {
  int cols = 11;
  int rows = 15;
  vector<vector<char>> matrix1(rows, vector<char>(cols));
  vector<vector<char>> matrix2(rows, vector<char>(cols));

  Board gameBoard1{matrix1};
  Board gameBoard2{matrix2};
  TextDisplay * ob = new TextDisplay(&gameBoard1, &gameBoard2);
  gameBoard1.attach(ob);
  gameBoard1.render();
  gameBoard2.attach(ob);
  TrieNode *commands = new TrieNode; //create new command tree with given vector of commands
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

  //process the commands 
  string input;
  
  //render empty board

  cout<<"input command: ";
 while( getline (cin, input) ){
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
      int multi = result.first;
      string fullCommand = commands->search(result.second);
      
      //do the thing 
      if(fullCommand == "drop"){
        
      //use levels to generate next block 
      }else if(fullCommand == "left"){

      }else if(fullCommand == "right"){

      }else if(fullCommand == "down"){

      }

      //render board
    }

    

  

  }
  

  //deallocate 
  delete commands; 
}
