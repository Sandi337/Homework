//這題會考 prefix_sum
#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int p[100001];

void sol(){
    memset(p,0,sizeof(p));
    int A,B,C,D;
    long long ans = 0;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    for(int x = A;x <= B;x++){
        p[x + B] += 1;
        p[x + C + 1] -= 1;
    }
    for(int i = A+B; i <= B + C; ++i){
        p[i] += p[i - 1];
    }

    for(int xy = 0; xy <= B + C; ++xy){
        long long num_of_valid_z = max(0, min(D, xy - 1) - C + 1);
        ans += p[xy] * num_of_valid_z;
    }
     
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--) sol();
    return 0;
}