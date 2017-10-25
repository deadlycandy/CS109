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
   Graph G(10);
   G.randomGraph(.20, 10);
   
   cout << endl;
   G.printG();
   cout << endl;
   float avgG = 0;
   for(int i = 0; i < G.V(); i++){
      cout << endl << i+1 << ": ";
      vector<int> temp = path(G,0, i);
      for(int it = 0; it < temp.size(); it++){
           cout << temp[it] << " ";
/*         if(k ==temp.size()-1){
            cout << "\nPath cost: " << temp[k] << endl;
            avgG += temp[k];
         }else{
            cout << temp[i] << " ";
         }*/
      }
    } 
   cout << endl << "Average cost of path: " << avgG << endl;



   return 0;
}

vector<int> path(Graph G, int source, int w){
   priority_queue< pair<float,int>, vector<pair<float, int> >, std::greater<pair<float, int> > > q;
   vector<float> dist(G.V(),INF);
   vector<int> prev(G.V(),-1);
   vector<int> path(G.V());
   if(0 <= source && source < G.V() && 0 <= w && w < G.V()){   

      for(int v = 0; v < G.V(); v++){
         if(v != source){
            dist[v] = INF;
            prev[v] = -1;
            pair<float, int> nodeV(INF, v);
            q.push(nodeV);
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
         if(prev[w] != -1){
//cout << endl << "prev: " << prev[w] << endl;
            int backptr = w;
            float pathCost; 
           int i = 0;
            pathCost += dist[backptr];
///cout << endl << "Path Cost: " << pathCost << endl;
            while (prev[backptr] != -1){
//cout << endl << "backptr: " << backptr << endl;
               path[i] = backptr;
               pathCost += dist[backptr];
               backptr = prev[backptr];
            i++;
            }
         //path.insert(path.begin(), source);
           // path.push_back(pathCost);
/*for(int i = 0; i < path.size(); i++){
cout<< endl << "p :" << path[i] << endl;
}*/
            path.resize(i);
            return path;
         }
         vector<float> neighbors = G.neighbors(u.second);
//cout << endl << "Neighbors: " << neighbors.size() << endl;
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

