#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "functions.h"
#include "commandInterpreter.h"

using namespace std;

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
  int seed = 0;
  string scriptfile1 = "";
  string scriptfile2 = ""; 
  int startlevel = 0;

  //process Game Paramters and display
  processGameParameters(argc, argv, text, seed, scriptfile1, scriptfile2, startlevel);
  prettyPrintGameParameters(text, seed, scriptfile1, scriptfile2, startlevel);

  //create new command tree with given vector of commands
  TrieNode *commands = new TrieNode; 
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

  //---------------- process player commands ------------------
  //NEED TO DO ELSEWHERE
  string input;
  cout<<"begin inputing commands"<<endl;
  while( getline (cin, input) ){
   
      auto result = seperateStringFromInt(input);
      string fullCommand = commands->search(result.second);

      //should also output player
      cout<<"full command: "<<fullCommand<<endl; //this is feedback for the command

      //send to model of MVC design pattern

      //update score 
      //render board from the commands
      //ie  clear lines, display score 

      //special actions 
      //if speical actions happen, render board again  

  }


  //deallocate commands
  delete commands; 
}
