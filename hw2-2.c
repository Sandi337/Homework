#include <stdio.h>

int A,B,C;

int main () {
    scanf("%d %d %d", &A, &B, &C);

    int a = ((A + B+ C)/2 )- B;
    int b = A - a;
    int c = C - a;
    printf("%d %d %d", a, b, c);
}