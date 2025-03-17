#include <stdio.h>

int calones(int x){
    int count = 0;
    while(x > 0){
        if(x % 10 == 1){
            count += 1;
        }
        x /= 10;
    }
    return count;
}

#define MAX_10 1000000
int prefix[MAX_10 + 1];
void solve(){
    int a, b;
    scanf("%d %d",&a, &b);
    int ans = 0;
    ans = prefix[b]- prefix[a-1];
    printf("%d\n",ans);
}

int main() {
    for(int i = 1;i <= MAX_10;i++){
        prefix[i] = prefix[i-1] + calones(i);
    }
    int t;
    scanf("%d", &t);
    while(t --) solve(); 
    return 0;
}