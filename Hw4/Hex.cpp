/*
Rahil Bhatnagar
Hw4
Hex.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

#include "Graph.h"
#include "Hex.h"

const int INF = 9999;

using namespace std;

Hex::Hex(int size){
   board.resize(size+1, vector<string>(size+1, " "));
   boardGraph = Graph(size*size);
   this->size = size;
}

void Hex::printBoard(){
   //prints out row of R's 
    cout << "  ";
    for(int k = 1; k < this->board.size(); k++)
       cout << "R   ";
    cout << endl;

   //Nested loops to print out status of board
    string spaces = " ";
    for(int i = 1; i < this->board.size(); i++){
       cout << spaces;
       spaces += " ";
       cout << "B ";
   
       //prints out each row and status of the space
       for(int j = 1; j < this->board[i].size(); j++){
          if(this->board[i][j] == " "){
             cout << ".";
          }else{
             cout << this->board[i][j];
          }      
          if(j < this->board[i].size() - 1)
             cout << " - ";
       }
       cout << " B" <<endl;

       //Used to create a hex pattern
       if(i < this->board.size() ){
          cout << spaces << " ";
          for(int k = 1; k < this->board.size()-1; k++)
             cout << " \\ /";
          cout << " \\" << endl;
       }
       spaces += " ";
    }
    
    //prints a row of R's
    cout << spaces;
    for(int k = 1; k < this->board.size(); k++)
       cout << "R   ";
    cout << endl;
}

void Hex::playerMove(string player, int x, int y){
   if(1 <= x && x <= this->board.size() && 1 <= y && y <= this->board.size() && this->board[x][y] == " "){
      this->board[x][y] = player;
      int node = cordToNode(x,y);
      
         if(player == this->bluePlayer){
            if(validConnections(x-1,y,player)){
               int newNode = cordToNode(x-1,y);
               this->boardGraph.set_edge_value(newNode,node,1);
            }
            if(validConnections(x-1,y+1,player)){
               int newNode = cordToNode(x-1,y+1);
               this->boardGraph.set_edge_value(newNode,node,1);
            }
            if(validConnections(x,y+1,player)){
               int newNode = cordToNode(x,y+1);
               this->boardGraph.set_edge_value(newNode,node,1);
            }
            if(validConnections(x+1,y,player)){
               int newNode = cordToNode(x+1,y);
               this->boardGraph.set_edge_value(newNode,node,1);
            }
            if(validConnections(x+1,y-1,player)){
               int newNode = cordToNode(x+1,y-1);
               this->boardGraph.set_edge_value(newNode,node,1);
            }
            if(validConnections(x,y-1,player)){
               int newNode = cordToNode(x,y-1);
               this->boardGraph.set_edge_value(newNode,node,1);
            } 
            this->boardGraph.set_edge_value(node,node,1);
         }else{
            if(validConnections(x-1,y,player)){
               int newNode = cordToNode(x-1,y);
               this->boardGraph.set_edge_value(newNode,node,-1);
            }
            if(validConnections(x-1,y+1,player)){
               int newNode = cordToNode(x-1,y+1);
               this->boardGraph.set_edge_value(newNode,node,-1);
            }
            if(validConnections(x,y+1,player)){
               int newNode = cordToNode(x,y+1);
               this->boardGraph.set_edge_value(newNode,node,-1);
            }
            if(validConnections(x+1,y,player)){
               int newNode = cordToNode(x+1,y);
               this->boardGraph.set_edge_value(newNode,node,-1);
            }
            if(validConnections(x+1,y-1,player)){
               int newNode = cordToNode(x+1,y-1);
               this->boardGraph.set_edge_value(newNode,node,-1);
            }
            if(validConnections(x,y-1,player)){
               int newNode = cordToNode(x,y-1);
               this->boardGraph.set_edge_value(newNode,node,-1);
            } 
            this->boardGraph.set_edge_value(node,node,-1);
         }
   }
}

bool Hex::validConnections(int x, int y, string player){
  if(1 <= x && x < this->board.size() && 1 <= y && y < this->board.size() && this->board[x][y] == player){
      return true;
   }
   return false;
}

int Hex::cordToNode(int x, int y){
   return (x*size-(size-1)) + (y-1);
}



void Hex::checkWin(){

}

void Hex::printBoardGraph(){
    this->boardGraph.printG();
}
