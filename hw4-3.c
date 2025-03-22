#include <stdio.h>
#include <string.h>

int a[10000005] ;

int main(){
    int T;
    int n;

    int ans;

    scanf("%d",&T);
    while(T--) {
        memset(a , 0, sizeof(a));
        scanf("%d",&n);
        for(int  i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            if (i == 1){
                ans = a[i];
            }else{
                ans = ans ^ a[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}