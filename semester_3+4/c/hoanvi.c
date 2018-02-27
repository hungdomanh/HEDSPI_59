#include <stdio.h>
int a[1000];
int b[1000];
int n;
int count;

void Init() {
    int i;
    n=3;
 //   scanf("%d",&n);
    for(i =0; i< n; i++) {
        //a[i] = i+1;
        b[i] = 1;
    }
    count = 0;
}

void pr() {
    int m;
    count++;
    if(count) {
        for(m=0; m<n; m++) {
            printf("%d ", a[m]);
        }
        printf("\n");
    }

}

int tt(int i, int j)  {
    int d;
    for(d=0; d<i; d++) {
        if(a[d] == j) return 1;
    }
    return 0;
}

void Try(int i) {
    int j;
    for(j=0; j<n; j++) {

        if(b[j] == 1)    {


            //if(!tt(i,j))    a[i] = j;
            a[i] = j+1;
            b[j] = 0;
            if(i==n-1) pr();
            else Try(i+1);
            b[j] =1;
        }
    }
}

int main() {
    //int leng, i;
  //  scanf("%d",&leng);
    //leng = 3;
    //for(i =0; i< leng; i++) {
      //  a[i] = 0;
    //}

//    deQuy(a, leng, 0);

    Init();
    Try(0);

    return 0;
}

