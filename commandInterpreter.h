#ifndef commandInterpreter_h 
#define commandInterpreter_h

#include <iostream>
#include <string>

using namespace std;

class TrieNode {
  string fullCommand;    // this is the full command it should be
  TrieNode **letters;   // array of TrieNode pointers

    public:
        TrieNode();
        ~TrieNode();
        void insert(const std::string &word);
        string search(const std::string &word);

};

#endif  // TRIE_H

