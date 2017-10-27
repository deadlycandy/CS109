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
   G.randomGraph(0.4f, 10.0f);
   G.printG();

   Graph tree;

   tree = prims(G);

   tree.printG();
}

Graph prims(Graph G){
   Graph tree(G.V());
   int numEdges = 0;
   int used[G.V()];

   for(int v = 0; v < G.V(); v++){
      used[v] = 0;
   }

   used[0] = 1;
   int x;
   int y;

   while(numEdges < G.V() - 1){
      int min =  INF;
      x = 0;
      y = 0;

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
//  tree.set_edge_value(x,y,min);
  cout << "x: " << x << " y: " << y << " weight: " << min << endl;
  used[y] = 1;
  numEdges++;
  }
  return tree;
}
