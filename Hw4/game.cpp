#include <iostream>
#include "Hex.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
   Hex game(3);
   
   int moves = 0;
   srand(time(NULL));
   int player;
   int x;
   int y;

/*   while(moves < 49){
      player = rand()%2 + 1;
      if(player == 1){
         x = rand()%7;
         y = rand()%7;
         game.playerMove("B", x, y);         
      }else{
         x = rand()%7;
         y = rand()%7;
         game.playerMove("R", x, y);
      }
      moves++;
   }*/

   game.playerMove("R", 3,3);

   game.playerMove("B", 3,2);

   game.playerMove("R", 3,1);

   game.playerMove("B", 2,3);
   game.playerMove("R", 2,2);

   game.playerMove("B", 2,1);
   game.playerMove("R", 1,3);

   game.playerMove("B", 1,2);
   game.playerMove("R", 1,1);

   game.printBoard();

   game.printBoardGraph();
   return 0;
}
