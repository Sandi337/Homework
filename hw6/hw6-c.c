#include <stdio.h>
#include <string.h>

#define MAX_X 1000000
#define MOD 1000000007

int x ;
char s[(MAX_X +1) * 3];//最長可能到max_x+1是因為要看cursor會跑到哪

void solve(){
  scanf("%d", &x);
  scanf("%s", s);
  long long ans = strlen(s);//strlen is O(n) 原始字串長度
  int len = ans;
  for(int i = 0; i < x && i < len ; ++i){
    if(len < x){
      //計算要複製的右部分長度
      //當前字串長度- 左部分末尾索引 就是 s[i+1]到s[len-1]的長度
      int copy_len = len - i - 1;
      //重複次數 (目標數值)s[i] - 1是因為要扣掉原字串有的部分
      for (int j = 0; j < s[i] - '1';++j){
        //將右部分複製到字串末尾 s + len 
        //例如，s = "231", i = 0, s + (i+1) = "31", 複製 "31" 到 s[3]
        strncpy(s + len , s + (i+1), copy_len);
        ans += copy_len;//答案增加右邊新增的長度
        len += copy_len;//當前的字串長度增加
        /*
        例如，s = "231", i = 0, s[i] = '2'，重複 2 - 1 = 1 次：
        初始：s = "231", len = 3。
        複製 "31" 到 s[3]，得到 s = "23131", len = 5, ans = 5。
        */
      }
      s[len] = '\0'; //s[len]再新增字串後，後面不會有\0 所以要手動加上
    }else{
        ans = ((i+1) + (s[i] - '0') *(ans -i- 1 + MOD) % MOD ) % MOD;
        //i+1是左邊的長度
        //這也是很重要的觀念要記得!! s[i] - '0'是因為要把字元轉成數字
        //s[i]原本是'2', '2' - '0' = 2
        //(總長度)ans - i - 1是因為要扣掉原字串有的部分也就是ans-(i+1)
        //另外加MOD是避免ans太小或i較大，導致負數
        //因為前面數值太小了並不會影響模數運算或溢位，只針對數值可能會很大的ans先取模避免溢位在取模
        //跟((a % MOD) * (b % MOD)) % MOD是一樣的只是簡化成(a * (b % MOD)) % MOD
    }   //對很小的數值取模是冗餘的
    }
  printf("%lld\n", ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--) solve();
  return 0;
}

/*
4
5
231
7
2323
6
333
24
133321333

25
1438
1101
686531475

*/