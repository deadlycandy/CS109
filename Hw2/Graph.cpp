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
   adj.resize(n,vector<int>(n,0));
   nodeData.resize(n);
   vertices = n;
   edges = 0;
}

//Manipulation Functions
void Graph::add(int x, int y){
   for(int i = 0; i < adj.size(); i++){
      for(int j = 0; j < adj[i].size(); j++){
         if(x == i && y == j){
            if(adj[i][j] == 0){
               cout << this->adj[i][j] << "\n";
               this->adj[i][j] = 1;
               cout << this->adj[i][j] << "\n";
            }
         }
      }
   }
}

//Access Functions
int Graph::V(){
   return this->vertices;
}

int Graph::E(){
   return this->edges;
}


