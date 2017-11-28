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
   this->nodeNum = size*size;
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
//cout << "b size" << this->board.size() << endl;
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
               this->boardGraph.set_edge_value(newNode,node,2);
            }
            if(validConnections(x-1,y+1,player)){
               int newNode = cordToNode(x-1,y+1);
               this->boardGraph.set_edge_value(newNode,node,2);
            }
            if(validConnections(x,y+1,player)){
               int newNode = cordToNode(x,y+1);
               this->boardGraph.set_edge_value(newNode,node,2);
            }
            if(validConnections(x+1,y,player)){
               int newNode = cordToNode(x+1,y);
               this->boardGraph.set_edge_value(newNode,node,2);
            }
            if(validConnections(x+1,y-1,player)){
               int newNode = cordToNode(x+1,y-1);
               this->boardGraph.set_edge_value(newNode,node,2);
            }
            if(validConnections(x,y-1,player)){
               int newNode = cordToNode(x,y-1);
               this->boardGraph.set_edge_value(newNode,node,2);
            } 
            this->boardGraph.set_edge_value(node,node,2);
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



bool Hex::checkWin(int source, int w){
   priority_queue< pair<int,int>, vector<pair<int, int> >, std::greater<pair<int, int> > > q;
   vector<int> dist(this->nodeNum,INF);
   vector<int> prev(this->nodeNum,-10);
   vector<int> path(this->nodeNum);

//cout << "Node Numbers" <<  this->nodeNum << endl;
//cout << source << endl;
//cout << w << endl;

   if(1 <= source && source < this->nodeNum && 1 <= w && w < this->nodeNum){   
      for(int v = 1; v < this->nodeNum; v++){
         if(v != source){
            dist[v] = INF;
            prev[v] = -10;
            pair<int, int> nodeV(INF, v);
            q.push(nodeV);
         }
      }

      pair<int,int> nodeU(0, source);
      dist[source] = 0;
      prev[source] = -10;
      q.push(nodeU);

      while (!q.empty()){
         pair<int, int> u(q.top());
         q.pop();  
//cout << u.second << endl;         
         //Termination sequence, checks if destination has been found.
//cout << "prev val " << prev[w] << endl;
         if(prev[w] != -10){
            cout << "Win" << endl;
            return false;
         }

         vector<float> neighbors = this->boardGraph.neighbors(u.second);
         for(int v = 1; v < neighbors.size(); v++){
            if(this->boardGraph.adjacent(u.second, v)){
//cout << "Looking at adjacent" << endl;
               if(prev[v] == -10){
                  dist[v] = 0;
                  prev[v] = u.second;
	          pair<int, int> newNode(dist[v], v);
	          q.push(newNode);
               }
            }
         }
      }
      cout << "No Path" << endl;
      path.resize(0);
      return false;
   }else{
      cout << "Indexes out of bound. No path" << endl;
      path.resize(0);
   }
   return false;   
}

void Hex::printBoardGraph(){
    this->boardGraph.printG();
}
