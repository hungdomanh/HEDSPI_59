/*
- Cách làm
   + Dùng 2 mảng để lưu đĩa của 2 người
   + Duyệt 2 mảng cùng lức với chỉ số i,j
   + So sánh: arr1[i] vs arr2[j] rồi tăng dần chỉ số i,j và biến đếm.
- Độ phức tạp:
   O(m+n)
   m n là số lượng đĩa của 2 người.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
   long la, lb, ia, ib, t0, t1, count, l;

   scanf("%d %d", &la, &lb);
   while(la != 0 && lb != 0) {

      int *a = new int[la];
      int *b = new int[lb];


      for(ia=0; ia<la; ia++) {
         scanf("%d", &a[ia]);
      }
      for(ib=0; ib<lb; ib++) {
         scanf("%d", &b[ib]);
      }

      if(la>lb)   l = la;
      else        l = lb;

      ia = 0;     ib = 0;     count = 0;
      while(ia<la && ib<lb) {
         if(a[ia] == b[ib])   {
            count ++;
            ia++;    ib++;
         }
         else if(a[ia] > b[ib])  ib++;
         else ia++;
      }

      printf("%d\n", count);
      scanf("%d %d", &la, &lb);
   }
   return 0;
}
