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



bool Hex::checkWin(string player){
   priority_queue< pair<int,int>, vector<pair<int, int> >, std::greater<pair<int, int> > > q;
   vector<int> dist(this->nodeNum,INF);
   vector<int> prev(this->nodeNum,-10);
   vector<int> path(this->nodeNum);

   vector<int> sources(this->board.size());
   vector<int> destination(this->board.size());

   if(player == this->bluePlayer){
      for(int i = 1; i < this->board.size(); i++){
         if(this->board[i][1] == this->bluePlayer){
            sources.push_back(cordToNode(i,1));
         }
      }

      for(int i = 1; i < this->board.size(); i++){
         if(this->board[i][this->board.size()-1] == this->bluePlayer){
            destination.push_back(cordToNode(i,this->board.size()-1));
         }
      }
   }else{

      for(int i = 1; i < this->board.size(); i++){
         if(this->board[1][i] == this->redPlayer){
            sources.push_back(cordToNode(1,i));
         }
      }

      for(int i = 1; i < this->board.size(); i++){
         if(this->board[this->board.size()-1][i] == this->redPlayer){
            destination.push_back(cordToNode(this->board.size()-1,i));
         }
      }
   }

   sources.shrink_to_fit();
   destination.shrink_to_fit();
   
   if(destination.size() == 0){
      return false;
   }


while(sources.size() > 0){
   int source = sources.back();
   sources.pop_back();

   if(1 <= source && source < this->nodeNum){//&& 1 <= w && w < this->nodeNum){   
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
         //Termination sequence, checks if destination has been found.
         for(int i = 0; i < destination.size(); i++){
            if(prev[destination[i]] != -10){
               cout << "Win" << endl;
               return true;
            }
         }

         vector<float> neighbors = this->boardGraph.neighbors(u.second);
         for(int v = 1; v < neighbors.size(); v++){
            if(this->boardGraph.adjacent(u.second, v)){
               if(prev[v] == -10){
                  dist[v] = 0;
                  prev[v] = u.second;
	          pair<int, int> newNode(dist[v], v);
	          q.push(newNode);
               }
            }
         }
      }
      path.resize(0);
   }else{
      path.resize(0);
   }   
}
cout<< "No winner" << endl;
return false;
}

void Hex::printBoardGraph(){
    this->boardGraph.printG();
}
