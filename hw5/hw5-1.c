#include <stdio.h>
#include <math.h>

long long x,y,ans;
int m;

int main (){

  scanf("%lld %lld %lld",&x , &y, &m);//數值 指數 模數
  if (y == 0) { // 處理 y = 0
    printf("%lld\n", 1 % m);
    return 0;
    }
  x = x % m; 
  ans = 1;

  while(y > 0){
    if (y % 2 == 1){ 
        //指數對應二進位除2計算2進位的位置
        //對應2進位的位置為1，才會把ans乘x 平方後的模數乘進來再取模數
        ans = (ans * x) % m;//a^2 mod m = ((a % m)*(a % m))% m
    }
    x = (x * x) % m;
    y = y / 2;
  }
  printf("%lld",ans);
  return 0;
}