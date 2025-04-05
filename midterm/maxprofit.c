#include <stdio.h>

long long p[1000005];
long long n;
int t,d;

int main(){

    scanf("%d",&t);
    scanf("%lld", &d);
    scanf("%lld",&p[0]);

    for(int i = 1;i < d;i++){
        scanf("%lld",&p[i]);

        if (p[i] -p[i-1] > 0){
            n += (p[i] -p[i-1]);
        }
    }
    printf("%lld",n);
    return 0;
}