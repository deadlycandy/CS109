/*
Rabhatna
shortestPath.cpp
Hw2
*/

#include <iostrea>
#include <queue>
#include <vector>
#include <utlity>


const int INF = 9999;

using namespace std;

//function defintions 
vector<int> vertices(vector<int> list);

vector<int> path(int u, int w);

int pathSize(int u, int w);


vector<int> path(int u, int w){
   std::priority_queue<pair<int,int>, std::vector<pair<int, int> >, std::greater<pair<int, int> > q;
   vector<int> dist;
   vector<int> prev;
   vector<int> path;

   for(int v = 1; v <= this.V(); v++){
      if(v != u){
         dist[v] = INF;
         prev[v] = NULL;
         pair<int, int> nodeV(INF, v);
      }
   }

   pair<int,int> nodeU = (0,u);
   dist[u] = 0;
   prev[u] = NULL;
   q.push(nodeU);

   while !q.empty(){
      u = q.pop();  
      
      if(prev[u.second] == w){
         int backptr = u.second;
         while (prev[backptr] != NULL){
            path.insert(path.begin(), backptr);
            backptr = prev[backptr];
         }
         return path;
      }

      neighbors = this.neighbors(u.second);
      for(int v = 1; v <= neighbors.size(); v++){
         newDist = dist[u.second] + this.get_edge_value(u.second, v);
         if(newDist < dist[v]){
            dist[v] = newDist;
            prev[v] = u.second;
	    pair<int, int> newNode = (newDist, v);
	    q.push(newNode);
         }
      }

   }
   return path;
}
 

int pathSzie(int u, int w){
   vector<int> path = this.path(u, w);
   return path.size();	
}

