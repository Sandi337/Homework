#include <stdio.h>
#include <string.h>

int T;
int is_equivalent(char *a ,char*b ,int len);

int main (){
    
    scanf("%d",&T);
    while(T--){
        char a[1005] = {'\0'},b[1005] = {'\0'};
        scanf("%s",a);
        scanf("%s",b);
        
        int len = strlen(a);

        int result = is_equivalent (a,b,len);
        if (result){
        printf("YES\n");
        }
        else {
        printf("NO\n");
        }
    }
}


int is_equivalent(char *a ,char*b ,int len){
   
    if(len % 2 == 1){
        //odd
        return strncmp(a,b,len) == 0;
        //內建函式比較字串，相等返回0
        
    }  
    else {
        //even
        int mid = len / 2; 
        int case_A = is_equivalent(a, b, mid) && is_equivalent(a + mid, b + mid, mid);
        int case_B = is_equivalent(a, b + mid, mid) && is_equivalent(a + mid, b, mid);
        return case_A || case_B;
    }
    
}