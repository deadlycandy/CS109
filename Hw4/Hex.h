/*
Rahil Bhatnagar
Hw4 
Hex.h
*/

#include <iostream>
#include "Graph.h"
#include <vector>

using namespace std;

#ifndef Hex_H
#define Hex_H

class Hex{

   private:
      vector< vector <char> > board;
      Graph boardGraph;
      char redPlayer = 'r';
      char bluePlayer = 'b';

   public:
      //constructor
      Hex(int size = 0);

      //Manipulation functions
      void playerMove(char player, int x, int y);

      //Access functions
      void printBoard();

};
#endif
