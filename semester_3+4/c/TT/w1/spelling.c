#include <stdio.h>
#include <string.h>

int so(char ch) {
   if(ch == 'a')  return 2;
   if(ch == 'b')  return 22;
   if(ch == 'c')  return 222;

   if(ch == 'd')  return 3;
   if(ch == 'e')  return 33;
   if(ch == 'f')  return 333;

   if(ch == 'g')  return 4;
   if(ch == 'h')  return 44;
   if(ch == 'i')  return 444;

   if(ch == 'j')  return 5;
   if(ch == 'k')  return 55;
   if(ch == 'l')  return 555;

   if(ch == 'm')  return 6;
   if(ch == 'n')  return 66;
   if(ch == 'o')  return 666;

   if(ch == 'p')  return 7;
   if(ch == 'q')  return 77;
   if(ch == 'r')  return 777;
   if(ch == 's')  return 7777;

   if(ch == 't')  return 8;
   if(ch == 'u')  return 88;
   if(ch == 'v')  return 888;

   if(ch == 'w')  return 9;
   if(ch == 'x')  return 99;
   if(ch == 'y')  return 999;
   if(ch == 'z')  return 9999;

   if(ch == ' ')  return 0;
}

void pr (char s[]) {
   int i;

   printf("%d", so(s[0]));
   for(i=1; i<strlen(s); i++) {
      if(so(s[i])%10 == so(s[i-1])%10)  printf(" ");
      printf("%d", so(s[i]));
   }
   printf("\n");
}



int main() {
   int n,i;
   char str[1002][1002];
   scanf("%d",&n);
   for(i=0; i<n; i++) {
      fflush(stdin);
      gets(str[i]);
   }

   for(i=0; i<n; i++) {
      printf("Case #%d: ", i+1);    pr(str[i]);
      //if(i<n-1)  printf("\n");
   }

   return 0;
}


