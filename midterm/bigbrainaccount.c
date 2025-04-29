#include <stdio.h>

int t;
long long x;

int main(){
    //while(t--){
        scanf("%lld",&x);

        int digit = 10;

        while((digit / 10) <= x){//digit用來計算十百千位數，並確保沒有超過x
            int num = (x % digit) / (digit / 10);
            //取出個位十位數字，digit = 100：num = (1234 % 100) / 10 = 34 / 10 = 3（十位）

            if(num >= 5){
                x = x + (digit - (x % digit));
            }

            digit = digit * 10;
        }
        printf("%lld",x);
    
    //}
    return 0;
}