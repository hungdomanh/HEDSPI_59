#include <stdio.h>
//_________________n phan tu_____chap m_____ vitri k
int a[10002];
int kt = 0;
int n,vitri,m;
int count;

void Init();
void Sinh();

////////////////////////
int main() {
   Init();
   Sinh();
   return 0;
}
///////////////////////

void Init() {
   int i;
   scanf("%d",&n);
   scanf("%d",&m);
   scanf("%d",&vitri);
   for(i =1; i<=m; i++) {
     a[i] = i;
   }
   count = 1;
}

void Sinh() {
   int i=m;
   if(count == vitri) {
      for(i=1; i<=m; i++) {
         printf("%d ",a[i]);
      }
      return ;
   }

   while(a[i] == n-m+i) {
      i--;
   }
   if(i<1)  printf("-1");
   else {
      a[i] += 1;
      int j;
      for(j=1; j<=m-i; j++) {
         a[i+j] = a[i] + j;
      }
      ++count;
      (void)Sinh();
   }
   return;
}
