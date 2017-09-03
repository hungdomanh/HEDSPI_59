#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15];
   char str2[15];
   int ret;



   strcpy(str1, "911aabcdef");
   strcpy(str2, "911");

   ret = strncmp(str1, str2, strlen(str2));

   if(ret < 0)
   {
      printf("1.str1 < str2");
   }
   else if(ret > 0)
   {
      printf("2.str1 > str2");
   }
   else
   {
      printf("3.str1 = str2");
   }

   return(0);
}
