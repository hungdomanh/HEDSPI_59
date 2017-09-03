#include <stdio.h>

char change(char n) {
   if(n=='1')  return '0';
   else return '1';
}



int main() {
   int n, i, j;
   char np[10000];

   scanf("%d",&n);
   scanf("%s",np);

   i =n-1;
   while(np[i] == '1') {
      i--;
   };

   if(i<0)  printf("%d",-1);
   else {
      np[i] = change(np[i]);
      for(j=i+1; j<n; j++) {
         np[j]= change(np[j]);
      }
      puts(np);
   }



   return 0;
}
