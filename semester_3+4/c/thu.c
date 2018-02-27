#include <stdio.h>
#include <stdlib.h>

typedef struct _v{
   struct _v *next;
   struct _v *back;
   int value, r, l;
}D;

typedef D* Data;

void Init(Data d) {
   d = (Data) malloc (sizeof(D));
   d->next = NULL;
   d->back = NULL;
   d->r = 0;
   d->l = 0;
   d->value = 0;
}

Data Creat(int x) {
   Data d;
   d = (Data) malloc (sizeof(D));
   d->next = NULL;
   d->back = NULL;
   d->r = 0;
   d->l = 0;
   d->value = x;
   return d;
}

void InsertR(Data d, int val) {
   if(d->next == NULL) {
      d->value = val;
   }
   else {
      //Data temp = Init();
      Data temp;  Init(temp);
      temp = d->next;
      while(val > temp->value) {
         temp = temp->next;
      }
      Data insert;  Init(insert);
      insert->value = val;
      insert->next = temp;
      insert->back = temp->back;
      d->r +=1;
      free(temp);
   }
}

void InsertL(Data d, int val) {
   if(!d->back) {
      d->value = val;
   }
   else {
      //Data temp = Init();
      Data temp;  Init(temp);
      temp = d->back;
      while(val > temp->value) {
         temp = temp->back;
      }
      Data insert;  Init(insert);
      insert->value = val;
      insert->back = temp;
      insert->next = temp->next;
      d->l +=1;
      free(temp);
   }
}


//////////////////////
int main()
{
   int n , m, k, i, j, a, b, dongcuoi[100003];
 //  scanf("%d %d %d", &n,&m ,&k);
   Data d[100003], R, dong1;
  // R = Init();    dong1 = Init();

   d[1] = Creat(1);
   d[2] = Creat(2);



   return 0;
}









