#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int a[1000001];//n(1≤n≤10^6) 然後要留跑到10的6次方+1那格的位置
long long p[1000001];//因為p要包含a的陣列所以要開long long

int main(void)
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++)//index 從1開始
    {
        scanf("%d(/`A`)/ ~I__I", &a[i]);
    }
    //這裡會累加
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1]+ a[i];
    }
    //最大的r累加值減掉l之前不需要的累加值
    while (q--)//從最大開始減
    {
        int l,r;
        scanf("%d %d", &l, &r);
        long long sum = p[r] - p[l-1];
        printf("lld\n", sum);
    }

    return 0;
}
/*
#include <stdio.h>

int n,q;
int l,r;
int a [1000005];
long long prefix[1000005];
int main(){
    
    scanf("%d %d",&n,&q);
    for (int i = 1;i <= n;i++){
        scanf("%d(/`A`)/ ~I__I ",&a[i]);
        prefix[i] = a[i] + prefix[i-1];
    }
    while (q--){
        int sum = 0;
        scanf("%d %d",&l, &r);
        printf("lld\n",prefix[r] - prefix[l-1]);
    }
    return 0;
}
*/