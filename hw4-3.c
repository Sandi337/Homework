#include <stdio.h>
#include <string.h>

int main(){
    int T;
    int n;
    int a[100000005] = {0};
    int sum[1000000005+1] = {0};

    scanf("%d",&T);
    while(T--) {
        memset(a , 0, sizeof(a));
        memset(sum , 0, sizeof(sum));
        scanf("%d",&n);
        for(int  i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            sum[a[i]] += 1;
            if(sum[a[i]] > 1){
                sum[a[i]] = 0;
            }
        }
        for (int  i = 1;i <= n; i++){
            if(sum[a[i]] != 0){
            printf("%d\n",a[i]);
            }
        }
    }
    return 0;
}