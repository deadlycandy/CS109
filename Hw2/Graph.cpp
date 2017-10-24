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
   adj.resize(n,vector<int>(n,0)); // range 0 to n (n noninclusive)
   nodeData.resize(n+1);
   vertices = n;
   edges = 0;
}

//Manipulation Functions

//Checks input and adds edge between valid indexs
void Graph::add(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      if(!this->adjacent(x,y)){
         this->adj[x][y] = 1;
      }
   }
}

//Checks input and removes edge between valid indexs
void Graph::remove(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      this->adj[x][y] = 0;
   }
}

//Generates a random graph
void Graph::randomGraph(float edgeDen, int distRange){
   //Random number generator
   default_random_engine generator(time(NULL));

   
   float edgeDensity = ceil(this->vertices * edgeDen);
   int totalEdges = edgeDensity * this->vertices;

   //Number generators with different ranges
   uniform_int_distribution<int> dis(1, edgeDensity);
   uniform_int_distribution<int> disN(1, this->vertices);  
   uniform_int_distribution<int> disR(1, distRange);

   //Loops through all nodes
   for(int i = 0; i < this->adj.size(); i++){
      int edgeNum = dis(generator);
      int j = 1; 

      //Runs till edge number has been met
      while(j <= ceil(edgeNum)){
         int node = disN(generator);
         if(!this->adjacent(i,node) && i != node){
            int counter = 0;
            vector<int> temp = this->neighbors(node);
            for(int k = 0; k < temp.size(); k++){
               if(temp[k] > 0){
                  counter++;
               }
            }

            //used to ensure a node does not end up with exessive connections maintains the avg
            if(counter < edgeDensity){
               this->adj[i][node] = disR(generator);
               j++;
            }
         }
      }
   }
}

//Checks input and sets node value
void Graph::set_node_value(int x, int a){ 
   if(0 <= x && x < this->vertices){
      this->nodeData[x] = a;
   }
}

//Checks input and sets edge value
void Graph::set_edge_value(int x, int y, int v){
  if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
     this->adj[x][y] = v;
  }
}

//Prints graph
void Graph::printG(){  
   for(int i = 0; i < this->adj.size(); i++){
      for(int j = 0; j < this->adj[i].size(); j++){
         cout<< this->adj[i][j] << " ";
      }
      cout << "\n";
    }  
}


//Access Functions

//Checks input and if two nodes are connected
bool Graph::adjacent(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      if(this->adj[x][y] != 0){
         return true;
      }
   }
  return false;  
}

//Checks input and returns the nodes row
vector<int> Graph::neighbors(int x){
   vector<int> temp(this->vertices);
   if(0 <= x && x < this->vertices){
      for(int j = 0; j < this->adj[x].size(); j++){
         temp[j] = this->adj[x][j];
      }
   }
    return temp;
}

//Returns number of vertices
int Graph::V(){
   return this->vertices;
}

//Returns number of edges
int Graph::E(){
   return this->edges;
}

//Checks input and returns node value
int Graph::get_node_value(int x){ 
   if(0 <= x && x < this->vertices){
      return this->nodeData[x];
   }
   return 0;
}

//Checks input and returns edge value
int Graph::get_edge_value(int x, int y){
   if(0 <= x && x < this->vertices && 0 <= y && y < this->vertices){
      return this->adj[x][y];
   }
   return 0; 
}
