#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "functions.h"

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

void prettyPrintGameParameters(bool text, int seed, string scriptfile1, string scriptfile2, int startlevel){
    
    cout << "------ Game Parameters: ------\n";
    cout << "Text Mode: " << (text ? "YES" : "NO") << "\n";
    cout << "Seed: " << seed << "\n";
    cout << "Script File 1: " << scriptfile1 << "\n";
    cout << "Script File 2: " << scriptfile2 << "\n";
    cout << "Start Level: " << startlevel << "\n";
    cout << "-------------------------------"<<endl;
    cout << endl;
}

void processGameParameters(int argc, char*argv[], bool &text, int &seed, string &scriptfile1, string &scriptfile2, int &startlevel){

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