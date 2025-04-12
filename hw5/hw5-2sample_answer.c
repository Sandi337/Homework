#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool eq(char a[], char b[] , int len){
    if (len % 2 == 1){
        if(strncmp(a, b, len) == 0){
            return true;
        }else{
            return false;
        }
    }
    else{
        return (eq(a ,b ,len/2) && eq(a+len/2 ,b+len/2 ,len/2)) || 
                (eq(a + len/2 ,b ,len/2) && eq(a, b + len /2 , len /2)); 
    }
}


int main (){

    int T;
    scanf("%d",&T);

    while(T--){
        char a[1005] = {'\0'},b[1005] = {'\0'};

        scanf("%s",a);
        scanf("%s",b);

        if (eq(a, b ,strlen(a))){
            printf("%s\n","Yes");
        }else {
            printf("%s\n","No");
        }
    }
    return 0;
}