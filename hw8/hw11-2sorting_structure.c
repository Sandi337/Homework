#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000

typedef struct{
    int a,b;
} Prod;
Prod p[MAX_N];

int cmp(const void *pl,const void *pr){
    Prod l = *(Prod *)pl;
    Prod r = *(Prod *)pr;
    return (l.a -l.b) - (r.a - r.b);
}
int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n; i++) scanf("%d", &p[i].a);
    for(int i = 0;i < n; i++) scanf("%d", &p[i].b);
    qsort(p, n,sizeof(Prod),cmp);
    long long sum = 0;
    int i = 0;
    for(; i <k; ++i) sum += p[i].a;
    for(; i <n && p[i].a < p[i].b; ++i) sum += p[i].a;
    for(; i <n; ++i) sum += p[i].b;
    printf("%lld\n", sum);
    return 0;
}