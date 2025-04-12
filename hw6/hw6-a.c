#include <stdio.h>

int n, k,count;
int a[25] = {0};

void randomsum(int pos, int sum){
    if(pos == n){
        if(sum == k)
            count++;
            return;   
    }  
    randomsum(pos + 1,sum);
    randomsum(pos + 1,sum + a[pos]);
    
}

int main(){

    scanf("%d %d", &n, &k);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }
    count = 0;
    randomsum(0,0);
    
    printf("%d\n",count);
    return 0;
}