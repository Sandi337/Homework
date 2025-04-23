/*
輸入 ab 3
會回傳
aaa
aab
aba
abb
baa
bab
bba
bbb
*/
#include <stdio.h>

char s[100];
char result[100];
int x;

void recursive(int pos){
  if(pos == x){//每個recursive都會有一個停止條件，這裡想設為小於字串的話你需要多設置一個位置的pos變數
    result[pos] = '\0';//新增字串的最後一定會需要有\0，這樣在print字串的時候才有辦法停止
    printf("%s\n",result);
    return;
  }
  
  for(int i = 0;s[i] != '\0';i++){
    result[pos] = s[i];//這裡會先遍歷所有s字串，填滿result[0]，所以s字串有多少就會先跑完，才進到result[1]
    recursive(pos + 1);//然後跑到x的字數後再按照s字符出現的順序處理所有組合
    //比如說Hfg ，會從result[0] = H的組合，再到result[0] = g的組合，最後到result[0] = g的組合
  }
}

int main(){
    
    scanf("%s", s); // ab
    scanf("%d", &x); // 3
    recursive(0);
}