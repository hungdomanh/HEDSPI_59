#include <stdio.h>

void ex(int *a, int i, int j) {
   int t;
   t = a[i];
   a[i] = a[j];
   a[j] = t;
}

int main() {
   int n, a[10000], i, j;

   scanf("%d", &n);
   i=0;
   while(i<n) {
      scanf("%d",&a[i+1]);
      i++;
   }


   i = n;
   while(a[i-1] > a[i] && i>-1) i--;
   i--;
   if(i<1) {
      printf("-1");
      return 0;
   }


   j=n;
   while(a[i] > a[j] ) j--;

   ex(a, i,j);


   for(j=i+1; j <= (n+i+1)/2; j++) {
      ex(a, j, n-j+i+1);
   }

   for(i=1; i<=n;i++) {
      printf("%d ", a[i]);
   }

   return 0;
}


