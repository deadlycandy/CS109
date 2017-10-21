/*
Graph.cpp
Hw2
Rabhatna
*/

#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"


//Constructor
Graph::Graph(int n){
   cout << "Constructor";
   adj.resize(n,vector<int>(n+1,0));
   nodeData.resize(n+1);
   vertices = n;
   edges = 0;
}

//Manipulation Functions
void Graph::add(int x, int y){
 /*  for(int i = 1; i <= adj.size(); i++){
      for(int j = 1; j <= adj[i].size(); j++){
         if(x == i && y == j){
            if(adj[i][j] == 0){
               cout << "add" << this->adj[i][j] << "\n";
               this->adj[i][j] = 1;
               cout << this->adj[i][j] << "\n";
            }
         }
      }
   }*/
   this->adj[x][y] = 1;
}

void Graph::remove(int x, int y){
   /*for(int i = 1; i <= adj.size(); i++){
      for(int j = 1; j <= adj[i].size(); j++){
         if(x == i && y == j){
            if(adj[i][j] == 0){
               cout << "del" << this->adj[i][j] << "\n";
               this->adj[i][j] = 0;
               cout << this->adj[i][j] << "\n";
            }
         }
      }
   }*/
   this->adj[x][y] = 0;
}

void Graph::randomGraph(float edgeDen, int distRange){
   srand(time(NULL));
   int edgeDensity = this->vertices * edgeDen;
   int totalEdges = edgeDensity * this->vertices;

   for(int i = 1; i <= this->adj.size(); i++){
      int edgeNum = rand() %edgeDensity+1;
      int j = 1;
      while(j <= edgeNum){
         int node = rand() % this->vertices + 1;
         if(!this->adjacent(i,node) && i != node){
            this->adj[i][node] = rand() % distRange + 1;
            j++;
         }
      }
   }
}

void Graph::set_node_value(int x, int a){
   this->nodeData[x] = a;
}

void Graph::set_edge_value(int x, int y, int v){
   this->adj[x][y] = v;
}

//Access Functions
bool Graph::adjacent(int x, int y){
   for(int i = 1; i <= adj.size(); i++){
      for(int j = 1; j <= adj[i].size(); j++){
         if(x == i && y == j){
            if(adj[i][j] != 0){
               return true;
            }
         }
      }
   }  
   return false;
}

vector<int> Graph::neighbors(int x){
   vector<int> temp;
   for(int i = 1; i <= adj.size(); i++){
      if(x == i){
         for(int j = 1; j <= adj[i].size(); j++){
               temp.push_back(this->adj[i][j]);
         }
         return temp;
      }
   }
   return temp;
}

int Graph::V(){
   return this->vertices;
}

int Graph::E(){
   return this->edges;
}

int Graph::get_node_value(int x){
   return this->nodeData[x];
}

int Graph::get_edge_value(int x, int y){
   return this->adj[x][y];
}
