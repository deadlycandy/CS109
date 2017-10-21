/*
Graph.cpp
Hw2
Rabhatna
*/

#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include <ctime>
#include <random>

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
   mt19937 generator(time(NULL));
   float edgeDensity = this->vertices * edgeDen;
   int totalEdges = edgeDensity * this->vertices;

   cout<< "\nEdge Density: " << edgeDensity;
   cout<< "\nTotal Edge: " << totalEdges;

   uniform_real_distribution<double> dis(0.0, edgeDensity);
   uniform_int_distribution<int> disN(1, this->vertices);  
   uniform_int_distribution<int> disR(1, distRange);

   for(int i = 1; i <= this->adj.size(); i++){
      int edgeNum = dis(generator);

      cout<< "\nEdge random: " << edgeNum;

      int j = 1;
      while(j <= edgeNum){
         int node = disN(generator);
         
         cout<< "\nNode: " << node;

         if(!this->adjacent(i,node) && i != node){
            int counter = 0;
            vector<int> temp = this->neighbors(node);
            for(int k = 1; k <=temp.size(); k++){
               counter++;
            }
	    if(counter < edgeDensity){
               this->adj[i][node] = disR(generator);
  
               cout<< "\nadj: " << edgeDensity;

               j++;
            }
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

void Graph::printG(){  
   for(int i = 1; i <= this->adj.size(); i++){
      for(int j = 1; j <= this->adj[i].size(); j++){
         cout<< this->adj[i][j] << " ";
      }
      cout << "\n";
    }  
}


//Access Functions
bool Graph::adjacent(int x, int y){
 /*  for(int i = 1; i <= this->adj.size(); i++){
      for(int j = 1; j <= this->adj[i].size(); j++){
         if(x == i && y == j){*/
            if(this->adj[x][y] != 0){
               return true;
            }
        // }
     // }
  // }  
   return false;
}

vector<int> Graph::neighbors(int x){
   vector<int> temp;
   for(int j = 1; j <= this->adj[x].size(); j++){
      temp.push_back(this->adj[x][j]);
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
