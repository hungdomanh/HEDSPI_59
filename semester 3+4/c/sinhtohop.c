#include <stdio.h>


int main() {
   int m, n, a[10000], i;

   scanf("%d %d", &n, &m);

   for(i=0; i<m; i++)   {
      scanf("%d", &a[i]);
   }
   i=m-1;
   while(a[i] == n-m+i+1) {
      i--;
   }
   if(i<0)  printf("-1");
   else {

      a[i] += 1;
      int j;
      for(j=1; j<m; j++) {
         a[i+j] = a[i] + j;
      }
      for(i=0; i<m; i++) {
         printf("%d ",a[i]);
      }
   }


   return 0;
}

