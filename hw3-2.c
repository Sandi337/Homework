#include <stdio.h>

#define max 200000

int n ; //西瓜數量
//是位置為i的西瓜編號
int arr[max + 1];//5, 3, 2, 1, 4 arr[1] = 5 =>位置1的西瓜編號是5

//編號為i的西瓜在第fruits[i]的位置
int fruits[max + 1];//fruits[5] = 1 編號 5 的西瓜在位置1
//fruits = 4, 3, 2, 5, 1

int order[max + 1];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        fruits[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &order[i]);
    }

    int now_pos = 0;
    for(int i = 1; i <= n; i++){
        if(fruits[order[i]] > now_pos){
            printf("%d",fruits[order[i]] - now_pos);
            now_pos = fruits[order[i]];
        }else{
            printf("0");
        }
        if (i < n){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    return 0;
}

