#include <stdio.h>
#include <math.h>

int fibo (int n) {
    int a1 = 1, a0=1, a2 = 2;
    if(n<2) return 1;
    int i=2;

    while(i<=n) {
        a2 = a0 + a1;
        a0 = a1;
        a1 = a2;
        i++;
    }
    return a2;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    if(k>n)    {
        printf("%d", (int)pow(2,n));
        return 0;
    }

    else if(k==n) {
        printf("%d", (int)pow(2,n)-1);
        return 0;
    }
    else {
        int i,kq, bnext ;
        int bk = (int) (pow(2,k) - 1);
        bnext = bk;
        int j =1;
        for(i=k+1; i<=n; i++)  {
            bnext = 2 * bnext - fibo(j);
            j++;
        }
        printf("%d", bnext);
    }

    return 0;
}
