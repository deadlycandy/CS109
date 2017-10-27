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

//Used to establish undiscovered distances
const float INF = 9999;

// Functon definition 
vector<float> path(Graph G, int source, int w);

using namespace std;

//Main for the entire program 
int main(){

   //Creates a random graph, finds path from 0 to n, then unpacks the returned data

   //Graph with .20 density and 10 distance range
   cout << endl << "Graph 1" << endl;
   Graph G(50);
   G.randomGraph(.20f, 10.0f);
   cout << endl;
   G.printG();
   cout << endl;
   float avgG = 0;
   int numPath = 0;
   for(int i = 0; i < G.V(); i++){
      cout << endl << i << ": ";
      vector<float> temp = path(G,0, i);
      for(int it = 0; it < temp.size(); it++){
         if(it ==temp.size()-1){
            cout << "\nPath cost: " << temp[it] << endl;
            numPath++;
            avgG += temp[it];
         }else{
            cout << temp[it] << " ";
         }
      }
    } 
   cout << endl << "Average cost of path: " << avgG/numPath << endl;

   //Graph with .40 density and 10 distance range 
   cout << endl << "Graph 2" << endl;
   Graph G1(50);
   G1.randomGraph(.40f, 10.0f);
   cout << endl;
   G1.printG();
   cout << endl;
   float avgG1 = 0;
   int numPath1 = 0;
   for(int i = 0; i < G1.V(); i++){
      cout << endl << i << ": ";
      vector<float> temp = path(G1,0, i);
      for(int it = 0; it < temp.size(); it++){
         if(it ==temp.size()-1){
            cout << "\nPath cost: " << temp[it] << endl;
            numPath1++;
            avgG1 += temp[it];
         }else{
            cout << temp[it] << " ";
         }
      }
    } 
   cout << endl << "Average cost of path: " << avgG1/numPath1 << endl;

   return 0;
}

/*
Utilizes Dijkstra's shortest path algorithm to compute the shortest path between two points. 

Function returns the path from source to destination with the cost of the path appended at the end.

Checks for valid input, to prevent bad data
*/

vector<float> path(Graph G, int source, int w){
   //using STL priority queue and storing pairs with priority being a float and int being the node
   priority_queue< pair<float,int>, vector<pair<float, int> >, std::greater<pair<float, int> > > q;
   vector<float> dist(G.V(),INF);
   vector<int> prev(G.V(),-1);
   vector<float> path(G.V());

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
         
         //Termination sequence, checks if destination has been found.
         if(prev[w] != -1){
            int backptr = w;
            float pathCost; 
            int i = 0;
            pathCost += dist[backptr];
            while (prev[backptr] != -1){
               path.insert(path.begin(), backptr);
               backptr = prev[backptr];
               i++;
            }
            pathCost = dist[w];
            path[i++] = pathCost;
            path.resize(i);
            return path;
         }

         vector<float> neighbors = G.neighbors(u.second);
         for(int v = 0; v < neighbors.size(); v++){
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
      path.resize(0);
      return path;
   }
   cout << "Indexes out of bound. No path" << endl;
   path.resize(0);
   return path;
}

 

