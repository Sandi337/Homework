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
    /*
    使用差分陣列（difference array）來計算某個區間內的計數
    目的是為每個x(從A到B），在陣列 p 中標記一個區間 $[x + B, x + C]$，表示這個區間的計數加 1。
    具體來說：
    p[x + B] += 1：表示區間的起點。
    p[x + C + 1] -= 1：表示區間的終點（不包含 x + C + 1）。
    */
    for(int x = A;x <= B;x++){
        p[x + B] += 1;
        p[x + C + 1] -= 1;
    }
    /*計算前綴和
    前綴和正確反映了每個y位置的(x, y)對數量
    */
    for(int i = A+B; i <= B + C; ++i){
        p[i] += p[i - 1];
    }
    //對於給定的 $ xy $（即 $ y $），$ z $ 可以取的合法數量
    //p[xy] 表示 y = xy 時的(x, y)對數量。
    //min(D, xy - 1) 取 D 和 xy - 1 中較小值，作為z的上限
    for(int xy = 0; xy <= B + C; ++xy){
        //計算從 C 到 min(D, xy - 1) 的整數數量
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