#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//all of the functions used by main

pair<int, string> seperateStringFromInt (const string &input);
void prettyPrintGameParameters(bool text, int seed, string scriptfile1, string scriptfile2, int startlevel);
void processGameParameters(int argc, char*argv[], bool &text, int &seed, string &scriptfile1, string &scriptfile2, int &startlevel);



#endif