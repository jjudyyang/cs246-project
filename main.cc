#include <iostream>
#include <string>
#include <vector>
#include "board.h"
#include "blank.h"
#include "commandInterpreter.h"

using namespace std;

// String of current commands,  used to seperate where command starts to become unique 
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

int main () {
  
  //create new command tree with given vector of commands
  TrieNode *commands = new TrieNode;
  cout<<"size of command list: " <<validCommands.size()<<endl;
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

  //process the commands
  string input;
  cout<<"input command: ";
  while( getline (cin, input)){
    cout<<"result: "<<commands->search(input)<<endl;;
  }
  
  delete commands;

  

}
