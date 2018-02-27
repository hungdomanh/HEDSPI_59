/*
++++++Cách Làm++++++
Dùng mảng dong[]:
   dong[i] = j với + i là dòng thứ i
                   + j là vị trí đặt queen trong dòng i
Với i: 1->8 , cột[i] = 0
   dùng mảng cột[8] để kiểm tra từng vị trí, i có queen => cột[i] = 1
   kiểm tra cot[i] = 1?
Với i: 1->16 , chéo[i] = 0
   dùng 2 mảng chéo tr(top-left) và tl(top-rigth);
   nếu chéo có queen => chéo[i] = 1;
   kiểm tra chéo[i] < 2 ?
   nếu > 1 => chéo có 2 queen => KTM
++++++Độ phức tạp+++++
   O(1);
*/


#include <stdio.h>
#include <string.h>

int findCot(char* inp) {
   int i;
   for(i=0; i<=8; i++) {
      if(inp[i] == '*')   return i+1;
   }
   return 0;
}


int main() {
   char input[10][10];
   int i,cot[10],dong[10];
   int TL[20], TR[20], j;

   for(j=0; j<=18; j++) {
      TL[j] = 0;
      TR[j] = 0;
   }
   for(i=0; i<=10; i++) {
      cot[i] = 0;
   }

   for(i=1; i<=8; i++) {
      scanf("%s",&input[i]);

      dong[i] = findCot(input[i]);
      cot[dong[i]] = 1;
   }

   for(i=1; i<=8; i++) {
      if(cot[i] == 0)  {
         printf("invalid");
         return 0;
      }
   }

   for(i=1; i<=8; i++) {
      TL[dong[i] - i+8] += 1;
      TR[i + dong[i]-1] += 1;
   }

   for(i=1; i<=16; i++) {
      if(TL[i] > 1 || TR[i]> 1)  {
         printf("invalid");
         return 0;
      }
   }

   printf("valid");

   return 0;
}
