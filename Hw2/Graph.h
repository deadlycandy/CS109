/*
Graph.h
Hw 2
rabhatna
*/

#include<iostream>
#include<vector>
using namespace std;


#ifndef Graph_H
#define Graph_H

class Graph{
   private:
      vector< vector<int> > adj;
      vector<int> nodeData;
      int vertices;
      int edges;

   public:
      //Constructors and Destructor
      Graph(int n=0);
    

      //Access Functions
      int V();
      int E();
      bool adjacent(int x, int y);
      vector<int> neighbors(int x);
	
      //Manipulation Functions 
      void add(int x, int y);
      void remove(int x, int y);
      void randomGraph(float edgeDen, int distDen);
      void printG();

      //Get and set functions 
      int get_node_value(int x);
      void set_node_value(int x, int a);
      int get_edge_value(int x, int y);
      void set_edge_value(int x, int y, int v);      

};
#endif
