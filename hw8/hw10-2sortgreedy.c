#include <stdio.h>
#include <stdlib.h>
#define MAX_N 300000

int n , p ,k;
int a[MAX_N + 1];
long long ans [MAX_N + 1];

int cmp_less(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int solve(){
    scnaf("%d%d%d", &n, &p ,&k); 
    for(int i = 1; i<= n ; i++){
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n, sizeof(int),cmp_less);//一格大小為int
    for(int i = 1;i <= n;i++){
        if(i < k){//還沒買夠k的狀況，1~i的商品都沒有折扣
            ans[i] = ans[i - 1] + a[i];
        }else{
            ans[i] = ans[i - k] + a[i];
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n; i++){
        if(ans[i] <= p){//買到第i 個商品為止的時候只要小於p塊錢
            cnt = i;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

int main(){
    int t ;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}