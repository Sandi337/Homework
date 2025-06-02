#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
#define MAX_S 1000

char str[MAX_N][MAX_S + 1];

/* sort a string array 
str === &str[0] === &str[0][0];
str + l === str[l] === &str[l][0]
str + k === str[k] === &str[k][0]
const void *pl == str + k +> (char*)pl === &str[k][0]
*/
/* sort a int array :int arr[MAX_N]
arr === &arr[0]
arr + l === &arr[l]
arr + k === &arr[k]
const void *pl => arr + k => (int*)pl === &arr[k] => arr[k] == *(int*)pl
*/
int cmp_len(const void *pl,const void *pr){
    // int L = *((int*)pl);
    // char *L = *(char**)pl; // wrong
    char *L = (char*)pl; //correct
    char *R = (char*)pr; 
    //compare string :return strcmp(L,R)
    //下面是因為要比較長度
    size_t lenL = strlen(L);
    size_t lenR = strlen(R);
    if(lenL < lenR) return -1;
    if(lenL > lenR) return 1;
    return 0;
}
//check if substr is a substring ort str
int checkvalid(const char *substr, const char *str){
    size_t len_sub = strlen(substr);
    size_t len_str = strlen(str);
    for(int i = 0;i <len_str - len_sub +1; i ++){
        if(strncmp(substr, str + i ,len_sub) == 0){//要檢查的第一個字串,第二個字串,要檢查的長度
            return 1;//found
        }
    }
    return 0;// not found
}

int main(){
    int n ;
    scanf("%d", &n);
    for(int i =0; i<n ;i++){
        scanf("%s", str[i]);
    }
    qsort(str, n ,sizeof(str[0])/*sizeof(char) * (MAX_S + 1)*/,cmp_len);
    int OK = 1;
    for(int i = 1;i< n;i++){
        if(!checkvalid(str[i-1], str[i])){
            OK = 0;
            break;
        }
    }
    if(OK){
        printf("YES\n");
        for(int i= 0;i < n;i++){
            printf("%s\n",str[i]);
        }
    }else{
        printf("NO\n");
    }
}