#include <stdio.h>
#include <string.h>

char s[2000];

int check(int i,int j){
    if(i == j)return 0;
    while(i < j){
        if(s[i] != s[j])return 0;
        i++;
        j--;
    }
    return 1;
}

int main(){
    while (scanf("%s",s)!= EOF){
        int len = strlen(s);
        int count = 0;
        for (int i = 0; i < len; i++){
            for(int j = i;j < len ; j++){
                if(check(i,j))
                count ++;
            }
        }
        printf("%d\n",count);
    }
    return 0;

}