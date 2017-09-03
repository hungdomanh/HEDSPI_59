#include <stdio.h>
int a[10000];

int n=3;
int count;

void Init() {
    int i;
    scanf("%d",&n);
    for(i =0; i< n; i++) {
        a[i] = 0;
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

void Try(int i) {
    int j;
    for(j=0; j<=1; j++) {
        a[i] = j;
        if(i==n-1) pr();
        else Try(i+1);
    }

}

int main() {

    Init();

    Try(0);

    return 0;
}
