#include <stdio.h>
#include <string.h>

int max_bit(int x){
    int ans = 0;
    while(x > 0){
        x /= 2 ;
        ++ans;
    }
    return ans;
}

#define max_n 100000
int n;
int p[max_n+1];
int bit[32];

void solve(){

    memset(bit , 0, sizeof(bit));

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    for(int i = 0; i <n ;i++){
        ++bit[max_bit(p[i])];
    }
    long long ans = 0;
    for (int i = 0;i < 32;i++){
        ans += (long long)bit[i] * (bit[i] - 1) / 2;
    }
    printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}