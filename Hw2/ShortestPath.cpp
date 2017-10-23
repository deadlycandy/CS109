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

using namespace std;

//function defintions 


vector<int> path(Graph G, int u, int w){
   priority_queue< pair<int,int>, vector<pair<int, int> >, std::greater<pair<int, int> > > q;
   vector<int> dist(G.V());
   vector<int> prev(G.V());
   vector<int> path(G.V());

   for(int v = 0; v < G.V(); v++){
      if(v != u){
         dist[v] = INF;
         prev[v] = -1;
         pair<int, int> nodeV(INF, v);
      }
   }
cout << "1" << endl;
   pair<int,int> nodeU(0,u);
   dist[u] = 0;
   prev[u] = -1;
   q.push(nodeU);

   while (!q.empty()){
      pair<int,int> u(q.top());
          q.pop();  
cout << "2" << endl;      
      if(prev[u.second] == w){
         int backptr = u.second;
         while (prev[backptr] != -1){
            path.insert(path.begin(), backptr);
            backptr = prev[backptr];
         }
         return path;
      }
cout << "3" << endl;
      vector<int> neighbors = G.neighbors(u.second);
cout << "4" << endl;
      for(int v = 0; v < neighbors.size(); v++){
         int newDist = dist[u.second] + G.get_edge_value(u.second, v);
         if(newDist < dist[v]){
            dist[v] = newDist;
            prev[v] = u.second;
	    pair<int, int> newNode(newDist, v);
	    q.push(newNode);
         }
      }

   }
   return path;
}
 

/*int pathSize(Graph G, int u, int w){
   vector<int> path = path(G,u, w);
   return path.size();	
}*/

