#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "board.h"

using namespace std;

//all of the functions used by main

pair<int, string> seperateStringFromInt (const string &input);
void prettyPrintGameParameters(bool text, unsigned int seed, string scriptfile1, string scriptfile2, int startlevel);
void processGameParameters(int argc, char*argv[], bool &text, unsigned int &seed, string &scriptfile1, string &scriptfile2, int &startlevel);

vector<string> addInputSequenceToVector( string scriptfile);

//game logic 
void gameController( int argc, char* argv[]);
void processCommand(Board &board, string c);
void setLevel(Board &board, int level);

#endif