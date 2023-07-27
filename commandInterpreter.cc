#include "commandInterpreter.h"
#include <string>
#include <iostream>

//constructor
TrieNode::TrieNode(): fullCommand{""}, letters(new TrieNode*[26]){
    //intialize letters to all nullptr
    for(int i = 0; i < 26; ++i){
        letters[i] = nullptr;
    }
}

//destructors 
TrieNode::~TrieNode(){
    if( letters != nullptr ){
       for(int i = 0; i < 26; ++i){
        delete letters[i];
        } 
    }
    delete[] letters;
}

// ---------------- MEMBER FUNCTIONS --------------------
void TrieNode::insert(const string& word){
    //cout<<"adding "<<word<<endl;
    TrieNode* current = this;

    //add the command to tree
    for( char c : word){
        int index = c - 'a';

        if(current->letters[index] == nullptr){
            //making new node at index
            current->letters[index] = new TrieNode; 
            current->letters[index]->fullCommand = word;
        }else{
            current->letters[index]->fullCommand = "MUTIPLE";
        }

        //cout<<"letter: "<<c<<" command: "<<word<<endl;
        //update current to new node to add rest of the word
        current = current->letters[index];
    }

}

//check if "word" is valid prefix!
string TrieNode::search(const string& word){
    TrieNode* current = this;

    //traverse the tree to see if word corresponds to a command
    for( char c : word){
        int index = c - 'a';
        if( current->letters[index] == nullptr){
            //word does not exist, character of word is nullptr 
            return "ERROR: command does not exist";
        }
        else{
            // check the character to see if it is command
            current = current->letters[index];
        }
    }

    //if it gets to the end of the word, return the command
    //either going to be correct command or "MUTIPLE" -- should be error
    return current->fullCommand;
}

//function to seperate string from int

//transplant from main!



