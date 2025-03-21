#include<stdio.h>

int n, q;
int l, r, m;
int a[1000001];
long long pre[1000001];
//雖然最多的數值陣列就是10^6，但全部的加總可能會超出，這時候就要開long long
//全域陣列會自動初始化全部為0
int main(){
    
    scanf("%d %d",&n , &q);
    for(int i = 1 ;i <= n; i++){
        scanf("%d",&a[i]);
        if (a[i] <0){
            a[i] = 0;
        }
        pre[i] = pre[i - 1] + a[i];
        
    }
    while(q--) {
        scanf("%d %d %d",&l, &r, &m);
        printf("%lld\n",pre[l+m-1] - pre[l-1]);
    }
    
}