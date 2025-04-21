
#include <stdio.h>
#include <string.h>
#define mod 1000000007

char s [1000005];
int t,x;

int main(){
scanf("%d",&t);
while(t--){
 scanf("%d", &x);
 scanf("%s", s);
int len = strlen(s);
for(int i=0;i <x && i< len ;i++){
 int add = (s[i]- '0') * ((len - (i+1)) %mod);
 len = (len + add) %mod;
}
printf("%d\n",len);
}
return 0;
}