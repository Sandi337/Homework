

#include <stdio.h>

int n,k;
int p[1000];
int total,dis;

int main(){
    scanf("%d %d", &n ,&k);
    total = n;
    int start = 0;
    for (int i = 0;i < n; i++){
        p[i] = i + 1;
    }

    while(total > 1){
        start = (start + k - 1) % total;

        for (int i = start; i < total-1 ; i++){
            p[i] = p[i+1];
        }
        
        if (start > total){
            start = 0;
        }
        total--;
    }
    printf("%d",p[0]);
    return 0;
}
