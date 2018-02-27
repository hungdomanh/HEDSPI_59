#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
const int n = 5;
int perm[n];
bool used[n+1];

void generate(int at) {
   if (at == n) {
      for (int i = 0; i < n; i++) {
         printf("%d ", perm[i]+1);
      }
      printf("\n");
   }
   else { // decide what the at-th element should be
      for (int i = 0; i < n; i++) {
         if (!used[i]) {
            used[i] = true ; perm[at] = i;
            generate(at + 1);
            // remember to undo the move:
            used[i] = false ;
         }
      }
   }
}
int main() {
   memset (used , 0, n);
   generate (0);
   return 0;
}


