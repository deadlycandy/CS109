//Bhatnagar-conversion.cpp
//Converting given C file to C++ 

//Including external libraries
#include <iostream>
#include <vector>

using namespace std;

//Creating a constant
const int N = 40;

//Sumation function
inline void sum(int* p, int n, vector<int>& data){
   *p = 0;
   //computes sum
   for(int i = 0; i < n; i++){
      *p = *p + data[i];
   }
}

int main (){
   //variable declarations
   int i;
   int accum = 0;
   std::vector<int> data (N); 
  
   //inserts values 0-39 into data vector
   for(i = 0; i < N; i++){
      data[i] = i;
   }
 
   //calls sum function  
   sum(&accum, N, data); 

   //Prints sumation to console
   cout << "Sum is " << accum << "\n"; 

   return 0;
}

