#include <stdio.h>
#include <string.h>

int test(char* p1, char* p2) {
   int len1 = strlen(p1);
   int len2 = strlen(p2);
   int len = len1 - len2;

   if(len1-len2 == 0) return 0;
   else if(len == -1 || len == -4 || len == 3)  return 1;
   else return -1;
}

int main()
{
   int n,k,i, w[102], all[102];

   char turn[26], p1[4][20], p2[4][20];
   while(1) {
      scanf("%d",&n);  if(n==0) break;
      scanf("%d",&k);
      for(i=1; i<=n+1; i++) {
         w[i] = 0;
         all[i] = 0;
      }

      for(i=0; i<k; i++) {
         fflush(stdin);
         gets(turn);

         int p1,p2;
         char cho1[10],cho2[10];

         sscanf(turn,"%d %s %d %s", &p1, cho1, &p2, cho2);
         int t = test(cho1, cho2);
         if(t != 0) {
               all[p1] += 1;
               all[p2] += 1;
               if(t == 1 ) {
                  w[p1] += 1;
               }
               else    w[p2] += 1;
         }
      }

      for(i=1; i<=n; i++) {
         if(all[i] == 0) printf("-");
         else {
            printf("%.3f\n", (float)w[i]/(float)all[i]);
         }

      }
      printf("\n");

   }




   return 0;
}
