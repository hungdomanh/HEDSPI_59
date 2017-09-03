#include <stdio.h>
#include <iostream>
#include <cstring>
#include <math.h>

bool pick[40];

typedef struct _Oxy {
   float x;
   float y;
}Oxy;

Oxy *crane = new Oxy;
Oxy *wall = new Oxy;
int l, w, n, r;
int *test = new int;
int res = 999;

void reset() {
   for(int i=0; i<=l*w; i++) {
      test[i] = 0;
   }
}

int Full() {
   for(int i = 1; i<=l*w; i++) {
      if(test[i] == 0)  return 0;
   }
   return 1;
}

int ThoaMan(Oxy c, Oxy w) {
   float x = c.x- w.x;
   float y = c.y- w.y;
   if( sqrt(x*x + y*y) < r)   return 1;
   else return 0;

}

void generate(int at) {
   if (at == n) {
      reset();
      int dem = 0, ok = 0;
      for (int i = 0; i < n; i++) {
         if (pick[i]) {
            dem ++;
            for(int j = 1; j <= l*w; j++) {
               if(!test[j])   if( ThoaMan(crane[i], wall[j]) )   test[j] = 1;
            }
         }
         if(Full()) {
            ok = 1;
            break;
         }
      }
      if(ok) {
         if(res > dem)  res = dem;
      }
   }
   else {
      // either pick element no. at
      pick[at] = true ;
      generate(at + 1);
      // or don’t pick element no. at
      pick[at] = false ;
      generate(at + 1);
   }
}
////////////////
int main() {
   scanf("%d %d %d %d", &l, &w, &n, &r);
   int k = 1;
   for(int j = w/2; j > -w/2; j--) {
      for(int i = -l/2; i < l/2; i++) {
         wall[k].x = i + 0.5;
         wall[k].y = j - 0.5;
         k++;
      }
   }

   for(int i = 0; i<n; i++) {
      scanf("%f %f", &crane[i].x, &crane[i].y);
   }

   reset();
   generate (0);
   if(res != 999)  printf("%d", res);
   else printf("Impossible");

   return 0;
}
