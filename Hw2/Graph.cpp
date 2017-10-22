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
#include <cmath>
#include <typeinfo>

//Constructor
Graph::Graph(int n){
   cout << "Constructor";
   adj.resize(n,vector<int>(n,0));
   nodeData.resize(n+1);
   vertices = n;
   edges = 0;
}

//Manipulation Functions
void Graph::add(unsigned int x, unsigned int y){
   if(1 <= x <= this->vertices && 1 <= y <= this->vertices){
      this->adj[x][y] = 1;
   }
}

void Graph::remove(unsigned int x, unsigned int y){
   if(1 <= x <= this->vertices && 1 <= y <= this->vertices){
      this->adj[x][y] = 0;
   }
}

void Graph::randomGraph(float edgeDen, int distRange){
   default_random_engine generator(time(NULL));
   float edgeDensity = this->vertices * edgeDen;
   int totalEdges = edgeDensity * this->vertices;

   cout<< "\nEdge Density: " << edgeDensity;
   cout<< "\nTotal Edge: " << totalEdges;

   uniform_int_distribution<int> dis(1, edgeDensity);
   uniform_int_distribution<int> disN(1, this->vertices);  
   uniform_int_distribution<int> disR(1, distRange);

   for(unsigned int i = 1; i <= this->adj.size(); i++){
      int edgeNum = dis(generator);

      cout<< "\nEdge random: " << ceil(edgeNum);

      int j = 1;
      while(j <= ceil(edgeNum)){
         int node = disN(generator);
         j++;
         cout<< "\nNode: " << node;
         cout << "\nadj: " << this->adjacent(i,node) << endl;
/*         if(!this->adjacent(i,node) && i != node){
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
         }*/
      }
   }
}

void Graph::set_node_value(unsigned int x, int a){ 
   if(1 <= x <= this->vertices){
      this->nodeData[x] = a;
   }
}

void Graph::set_edge_value(unsigned int x, unsigned int y, int v){
  if(1 <= x <= this->vertices && 1 <= y <= this->vertices){
     this->adj[x][y] = v;
  }
}

void Graph::printG(){  
   for(unsigned int i = 1; i <= this->adj.size(); i++){
      for(unsigned int j = 1; j <= this->adj[i].size(); j++){
         cout<< this->adj[i][j] << " ";
      }
      cout << "\n";
    }  
}


//Access Functions
bool Graph::adjacent(unsigned int x, unsigned int y){
   for(int i = 1; i <= this->adj.size(); i++){
      for(int j = 1; j <= this->adj[i].size(); j++){
          if(x == i && y == j){
             cout << "Inside1: " << this->adj[i][j] << " ";
             return true;
          }
      }
   }
/*  if(1 <= x <= this->vertices && 1 <= y <= this->vertices){
     cout << "inside: ";
     cout << this->adj[x][y] << endl;
     if(this->adj[x][y] != 0){
       return true;
     }
  }*/
  return false;  
}

vector<int> Graph::neighbors(unsigned int x){
   vector<int> temp;
   for(unsigned int j = 1; j <= this->adj[x].size(); j++){
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

int Graph::get_node_value(unsigned int x){
   return this->nodeData[x];
}

int Graph::get_edge_value(unsigned int x, unsigned int y){
   if(1 <= x <= this->vertices && 1 <= y <= this->vertices){
      return this->adj[x][y];
   }
   return 0; 
}
