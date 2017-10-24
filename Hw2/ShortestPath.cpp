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

const float INF = 9999;
vector<int> path(Graph G, int source, int w);

using namespace std;

//function defintions 
int main(){
   Graph G(5);
   G.randomGraph(.35, 10);
   G.printG();

   vector<int> temp = path(G,0,90);
/*   cout << "back in main" << endl;
      int i = 0;
      for(; i < temp.size()-1; i++){
         cout << temp[i] << " ";
      } 
   cout << endl;
   i++;
   cout << "Path cost: " << temp[i] << endl;
  */ return 0;
}

vector<int> path(Graph G, int source, int w){
   priority_queue< pair<float,int>, vector<pair<float, int> >, std::greater<pair<float, int> > > q;
   vector<float> dist(G.V());
   vector<int> prev(G.V());
   vector<int> path;
   if(0 <= source && source < G.V() && 0 <= w && w < G.V()){   

      for(int v = 0; v < G.V(); v++){
         if(v != source){
            dist[v] = INF;
            prev[v] = -1;
            pair<float, int> nodeV(INF, v);
         }
      }
      pair<float,int> nodeU(0.0, source);
      dist[source] = 0;
      prev[source] = -1;
      q.push(nodeU);

      while (!q.empty()){
         pair<float,int> u(q.top());
         q.pop();  
//cout << " U: " << u.first << " " << u.second << endl;
//cout << "prev: " << prev[67] << endl;
         if(prev[w] != -1){
            int backptr = w;
            float pathCost; 
            pathCost += dist[backptr];
            while (prev[backptr] != -1){
               path.insert(path.begin(), backptr);
               pathCost += dist[backptr];
               backptr = prev[backptr];
            }
         //path.insert(path.begin(), source);
            path.push_back(pathCost);
            return path;
         }
         vector<float> neighbors = G.neighbors(u.second);
         for(int v = 0; v < neighbors.size(); v++){
//cout << " V : " << v;
            if(G.adjacent(u.second, v)){
               float newDist = dist[u.second] + G.get_edge_value(u.second, v); 
               if(newDist < dist[v]){
                  dist[v] = newDist;
                  prev[v] = u.second;
	          pair<float, int> newNode(newDist, v);
	          q.push(newNode);
               }
            }
         }
      }
      cout << "No Path" << endl;
      return path;
   }
   cout << "Indexes out of bound. No path" << endl;
   return path;
}

 

/*int pathSize(Graph G, int u, int w){
   vector<int> path = path(G,u, w);
   return path.size();	
}*/

