/*
Rahil Bhatnagar
Hw4
Hex.cpp
*/

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Hex.h"

using namespace std;

Hex::Hex(int size_{
   board.resize(size, vector<char>(size, ' '));
   Graph boardGraph(size*size);
}

void Hex::printBoard(){
    cout << "R " * this->board.size() << endl;
    for(int i = 0; i < this->board.size(); i++){
       cout << "B "
       for(int j = 0; j < this->board[i].size(); j++){
          if(this->board[i][j] == ' '){
             cout << static_cast<char>(183);
          }else{
             cout << this->board[i][j];
          }      
          cout << "-";
       }
       cout << " B" <<endl;
       if(i < this->board.size() - 1)
          cout << "\\ /" * this->board.size() << endl;
    }
    cout << "R " * this->board.size() << endl;
}
