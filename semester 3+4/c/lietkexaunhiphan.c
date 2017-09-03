#include <stdio.h>
#include <math.h>

/////////  do dai ____ vi tri _____ bao nhieu so
int a[1000002];
int kt = 0;
int n,vitri,so;
int count;

int test(int i);
void Init();
void pr();
void Try(int i);

////////////////////////
int main() {
   Init();
   Try(0);
   if(count<vitri)  printf("-1");
   return 0;
}
///////////////////////
void Init() {
   int i;
   scanf("%d",&n);
   scanf("%d",&vitri);
   scanf("%d",&so);
   for(i =0; i<=n; i++) {
     a[i] = 0;
   }
   if(so>n)  {
      so = n;
      count = 1;
   }

   count = 0;
}

void pr() {
   int m;
   count ++;
   if(count == vitri)  {
      kt = 1;
      for(m=0; m<n; m++) {
         printf("%d",a[m]);
         if(m<n-1) printf(" ");
      }
      return ;
   }
}

int test(int i) {
   int lan,i2;
   lan = so;
   i2 = i;
   while(lan>0) {
      if(a[i2] == 1)  return 1;
      i2--;
      lan--;
   }
   return 0;

}

void Try(int i) {
    int j;
    if(kt)  return;
    for(j=0; j<=1; j++) {
        a[i] = j;
        if(i==n-1 && test(i))  pr();
        else {
           if(i>=so-1) {
              if(test(i))  Try(i+1);
           }
           else   Try(i+1);
        }
    }

}

