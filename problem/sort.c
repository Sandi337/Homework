#include <stdio.h>
#define MAX 100005

int n;

int arr[MAX + 1][2];
int order[MAX + 1];

int main(){
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        order[i] = i+1;
    }
    for (int i = 0;i < n-1;i++){
        for(int j = 0; j < n - i- 1;j++){
            if(arr[j][0] > arr[j+1][0] || (arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1])){
                // 交換 arr
                int temp0 = arr[j][0];
                int temp1 = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp0;
                arr[j + 1][1] = temp1;
                // 交換 order
                int temp = order[j];
                order[j] = order[j+1]; 
                order[j+1] = temp;
            }
        }
    }
    for (int i = 0;i < n;i++){
        if(i == n){
            printf("%d\n",order[i]);
        }else{
            printf("%d ",order[i]);
        }
        
    }
    return 0;
}