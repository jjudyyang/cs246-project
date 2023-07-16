#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "board.h"
#include "blank.h"
#include "commandInterpreter.h"

using namespace std;

// String of current commands
// new commands can be added, or removed ( need to modify command while loop for new commands)
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
  
  TrieNode *commands = new TrieNode; //create new command tree with given vector of commands
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

  //process the commands
  string input;
  cout<<"input command: ";
  while( getline (cin, input)){
    //check if there is a multiplier 
    auto result = seperateStringFromInt(input);
    cout<<"int "<<result.first<<endl;
    cout<<"str "<<result.second<<endl;

    cout<<"full command: "<<commands->search(result.second)<<endl;

    //DO WHATEVER WITH COMMANDS HERE
    // #############################
    // #############################
    // #############################
    // #############################
    // #############################

  }
  

  //deallocate 
  delete commands; 
}
