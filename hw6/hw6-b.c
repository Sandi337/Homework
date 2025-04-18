#include <stdio.h>
#include <string.h>

int t,len;
char s[2005];

int palindrome(char s[],int l){
    int count = 0;
    //odd
    for(int i = 0 ;i < len ; i++){
        for(int k = 0; i - k>=0 && i+k < len ;k++){
            if(s[i-k] != s[i+k]) break;
            count ++;
        }
    }
    //even
    for(int i = 0 ;i < len+1 ; i++){
        for(int k = 0; i - k>=0 && i+k < len ;k++){
            if(s[i-k] != s[i+k + 1]) break;
            count ++;
        }
    }
    return count;
}

int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%s",s);
        len = strlen(s);
        printf("%d\n", palindrome(s,len));
    }
    return 0 ;
}