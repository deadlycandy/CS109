/*
Rahil Bhatnagar 
Hw3
MST.cpp
*/

#include <iostream>
#include "Graph.h"

const int INF  = 9999;

using namespace std;
Graph prims(Graph G);

int main(){
   Graph G(10);

   G.add(0,2);
   G.add(0,8);
   G.add(1,5);
   G.set_edge_value(1,3, 4.20f);
   G.add(2,5);
   G.add(3,8);
   G.add(3,9);
   G.add(4,5);
   G.add(5,7);
   G.set_edge_value(5,8, 4.20f);
   G.add(6,7);
   
   cout << "Handmade Graph: " << endl;
   G.printG();

   Graph tree;

   cout << "MST for Handmade Graph: " << endl;
   tree = prims(G);

   cout << endl;

   tree.printG();

   cout << endl << endl;

   Graph G1(100);

   G1.randomGraph(0.4f, 10.0f);

   cout << "Randomly made Graph: " << endl;
   
   G1.printG();

   cout << "MST for Randomly made Graph: " << endl;
 
   Graph tree1;

   tree1 = prims(G1);
   
   cout << endl;   

   tree1.printG();
}

//Prims algorithm finds a MST in a graph
Graph prims(Graph G){
   Graph tree(G.V());
   int numEdges = 0;
   int used[G.V()];
   
   //Used is utlized to track what vertices have been visited before
   for(int v = 0; v < G.V(); v++){
      used[v] = 0;
   }

   used[0] = 1;
   int x;
   int y;
  
   //Runs for V-1 iterations 
   while(numEdges < G.V() - 1){
      int min = INF;
      x = 0;
      y = 0;
      
      //Runs through the Adj matrix checking for min paths between vertices 
      for(int i = 0; i < G.V(); i ++){
         if(used[i] == 1){
           for(int j = 0; j < G.V(); j++){
              if(used[j] == 0 && G.adjacent(i,j)){
                if(G.get_edge_value(i,j) < min){
                    min = G.get_edge_value(i,j);
                    x = i;
                    y = j;
                }
              }
           }
        }
     }

  //Inputs the min path into a tree (graph)
  tree.set_edge_value(x,y,min);
  cout << "x: " << x << " y: " << y << " weight: " << min << endl;
  used[y] = 1;
  numEdges++;
  }
  return tree;
}
