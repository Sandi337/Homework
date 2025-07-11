#include <stdio.h>

int main(){
    
    int n,k;
    scanf("%d%d", &n, &k);

    int points[n + 1];
    points[0] = 0;

    int now = points[0];
    int bike = 0;
    int flag = 1;

    for(int i = 1;i <= n; i++){
        scanf("%d", points + i);

        if(points[i] - points[i - 1] > k)
            flag = 0;

        if(now + k < points[i]){
            bike++;
            now = points[i - 1];
        }
    }
    if(flag)
        printf("%d\n", bike);
    else    
        printf("The Legend Falls.\n");
}