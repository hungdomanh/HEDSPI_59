#include <stdio.h>
int a[10002];
int b[10002];
int n, k;
int count;

void Init() {
    int i;
    scanf("%d %d", &n, &k);
    for(i =0; i< n; i++) {
        a[i] = i+1;
        b[i] = 1;
    }
    count = 0;
}

void pr() {
    int m;
    count++;

    if(count == k) {
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
    if(count < k)
    for(j=0; j<n; j++) {

        if(b[j] == 1)    {

            a[i] = j+1;
            b[j] = 0;
            if(i==n-1) pr();
            else Try(i+1);
            b[j] =1;
        }
    }

}

int main() {

    Init();
    Try(0);
   if(count < k)      printf("-1");
    return 0;
}


