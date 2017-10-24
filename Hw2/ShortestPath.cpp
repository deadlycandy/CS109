/*
Rabhatna
shortestPath.cpp
Hw2
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include "Graph.h"

const int INF = 9999;
vector<int> path(Graph G, int source, int w);

using namespace std;

//function defintions 
int main(){
   Graph G(10);
   G.randomGraph(.5, 10);
   G.add(0,1);
   G.add(1,3);
   G.add(3,2);
   G.add(2,4);
   //path 0 - 3 - 2 - 4 or 0 - 1 - 3 - 2 - 4 
   G.printG();

   vector<int> temp = path(G,0,4);
   cout << "back in main" << endl;

      for(int i = 0; i < temp.size(); i++){
         cout << temp[i] << " ";
      } 
   cout << endl;
   return 0;
}

vector<int> path(Graph G, int source, int w){
   priority_queue< pair<int,int>, vector<pair<int, int> >, std::greater<pair<int, int> > > q;
   vector<int> dist(G.V());
   vector<int> prev(G.V());
   vector<int> path;

   for(int v = 0; v < G.V(); v++){
      if(v != source){
         dist[v] = INF;
         prev[v] = -1;
         pair<int, int> nodeV(INF, v);
      }
   }
   pair<int,int> nodeU(0, source);
   dist[source] = 0;
   prev[source] = -1;
   q.push(nodeU);

   //for(int k = 0; k < 10; k++){
   while (!q.empty()){
      pair<int,int> u(q.top());
          q.pop();  
//cout << "u: " << u.second << " w: " << w << endl;      
      if(prev[w] != -1){
         int backptr = w;
         cout << "prev " << prev[w] << endl;
         while (prev[backptr] != -1){
            path.insert(path.begin(), backptr);
            backptr = prev[backptr];
         }
         path.insert(path.begin(), source);
         return path;
      }
      vector<int> neighbors = G.neighbors(u.second);
      for(int v = 0; v < neighbors.size(); v++){
         if(G.adjacent(u.second, v)){
            int newDist = dist[u.second] + G.get_edge_value(u.second, v); 
//cout << "Dist u.s: " << dist[u.second] << " Get edge: " << G.get_edge_value(u.second, v) << endl; 
//cout << "new dist: " << newDist << " Dist v: " << dist[v] << endl;
            if(newDist < dist[v]){
               dist[v] = newDist;
               prev[v] = u.second;
	       pair<int, int> newNode(newDist, v);
	       q.push(newNode);
            }
          }
      }

   }
  cout << "No Path" << endl;
  return path;
}
 

/*int pathSize(Graph G, int u, int w){
   vector<int> path = path(G,u, w);
   return path.size();	
}*/

