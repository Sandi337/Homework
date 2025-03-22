#include <stdio.h>

int calones(int x){
    int count = 0;
    while(x > 0){
        //如果要檢查有多少個0-9的數字的話，只要改成x % 10 == 任一個數字就好!
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
    //a跟b是我要累計有多少個1的區間
    int a, b;
    scanf("%d %d",&a, &b);
    int ans = 0;
    ans = prefix[b]- prefix[a-1];
    printf("%d\n",ans);
}

int main() {
    //這概念真的很酷，他先遍歷所有數值到最大值
    //計算每個數值%10之後有沒有1，然後累加，比如說prefix[2] = prefix[1]再加calones(2)的結果
    //也就是prefix[2]沒有1，calone(2)回傳就是0，但他會承接prefix[1]的結果
    //最後我收到a跟b，我只需要用prefix[b]-prefix[a-1]，最大累加值的減掉最小值以前累加的數值(減去我不要的累加值)
    for(int i = 1;i <= MAX_10;i++){
        prefix[i] = prefix[i-1] + calones(i);
    }
    int t;
    scanf("%d", &t);
    while(t --) solve(); //這裡就只要呼叫function就好
    return 0;
}