#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

const int n = 8;
bool has_queen[n][n];
int queens_left = n;

void generate(int x, int y) {
   if (y == n) {
      generate(x+1, 0);
   }
   else if (x == n) {
      if (queens_left == 0) {
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               printf("%c", has_queen[i][j] ? 'Q' : '.');
            }
            printf("\n");
         }
      }
   }
   else {
      if (queens_left > 0 and no queen can attack cell (x,y)) {
         // try putting a queen on this cell
         has_queen[x][y] = true ; queens_left --;
         generate(x, y+1);
         // undo the move
         has_queen[x][y] = false ; queens_left ++;
      }
      // try leaving this cell empty
      generate(x, y+1);
   }
}

main() {
   memset(has_queen , 0, sizeof (has_queen ));
   generate(0, 0);
   return;
}


