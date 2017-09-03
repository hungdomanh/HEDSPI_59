#include <stdio.h>

const int n = 5;
bool pick[n];
void generate(int at) {
if (at == n) {
for (int i = 0; i < n; i++) {
if (pick[i]) {
printf("%d ", i+1);
}
}
printf("\n");
} else {
// either pick element no. at
pick[at] = true ;
generate(at + 1);
// or don’t pick element no. at
pick[at] = false ;
generate(at + 1);
}
}

generate (0);

