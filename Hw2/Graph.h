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
      bool adjacent(unsigned int x, unsigned int y);
      vector<int> neighbors(unsigned int x);
	
      //Manipulation Functions 
      void add(unsigned int x, unsigned int y);
      void remove(unsigned int x, unsigned int y);
      void randomGraph(float edgeDen, int distDen);
      void printG();

      //Get and set functions 
      int get_node_value(unsigned int x);
      void set_node_value(unsigned int x, int a);
      int get_edge_value(unsigned int x, unsigned int y);
      void set_edge_value(unsigned int x, unsigned int y, int v);      

};
#endif
