#include <stdio.h>

int t;
long long x;

int main(){
    //while(t--){
        scanf("%lld",&x);

        int digit = 10;

        while((digit / 10) <= x){
            int num = (x % digit) / (digit / 10);

            if(num >= 5){
                x = x + (digit - (x % digit));
            }

            digit = digit * 10;
        }
        printf("%lld",x);
    
    //}
    return 0;
}