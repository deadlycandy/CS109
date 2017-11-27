/*
Rahil Bhatnagar
Hw4 
Hex.h
*/

#include <iostream>
#include "Graph.h"
#include <vector>
#include <string>

using namespace std;

#ifndef Hex_H
#define Hex_H

class Hex{

   private:
      vector< vector <string> > board;
      Graph boardGraph;
      string redPlayer = "R";
      string bluePlayer = "B";
      int size;
      
      bool validConnections(int x, int y, string player);
      int cordToNode(int x, int y);
   public:
      //constructor
      Hex(int size = 0);

      //Manipulation functions
      void playerMove(string player, int x, int y);

      //Access functions
      void printBoard();
      void printBoardGraph();
      void checkWin();

};
#endif
