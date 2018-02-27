/*
++++++++ Cách làm+++++
Xây dựng 3 hàm cho 3 trường hợp
   TH1: đi ra và để U
      nếu muốn U gặp U: không đổi
      nếu muốn U gặp D: count+=1 ( đổi D thành U)
      nếu muốn D gặp D: count+=1 ( đổi D thành U khi đi ra)
      nếu muốn D gặp U: count+=2 ( đổi U thành D và D thành U khi đi ra)
   TH2: đi ra và để D <tương tự>
   TH3: đi ra để như mình muốn gặp
      nếu muốn != gặp: count+=1 ( đổi muốn thành gặp)
+++++++Độ phức tạp++++++
   TH1 TH2 TH3: O(n) <n là độ dài xâu input>
*/

#include <stdio.h>
#include <string.h>

int U1(char *st) {
   char str[10000];
   strcpy(str, st);
   int len = strlen(str);
   int i, count=0;
   for(i=1; i<len; i++) {
      if(str[i] == str[i-1] && str[i] == 'D') {
         count += 1;
         str[i] = 'U';
      }
      else  if(str[i] != str[i-1] ){
         if(str[i] == 'U') {
            count+=1;
         }
         else {
            count += 2;
            str[i] = 'U';
         }
      }
   }
   return count;
}

int D2(char *st) {
   char str[10000];
   strcpy(str, st);
   int len = strlen(str);
   int i, count=0;
   for(i=1; i<len; i++) {
      if(str[i] == str[i-1] && str[i] == 'U') {
         count += 1;
         str[i] = 'D';
      }
      else  if(str[i] != str[i-1] ){
         if(str[i] == 'D') {
            count+=1;
         }
         else {
            count += 2;
            str[i] = 'D';
         }
      }
   }
   return count;
}

int UD3(char *st) {
   char str[10000];
   strcpy(str, st);
   int len = strlen(str);
   int i, count=0;
   for(i=1; i<len; i++) {
      if(str[i] != str[i-1] ){
         count+=1;
      }
   }
   return count;
}


int main() {
   char str[10000];
   scanf("%s",&str);

   printf("%d\n", U1(str));
   printf("%d\n", D2(str));
   printf("%d", UD3(str));

   return 0;
}

