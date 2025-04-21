#include <stdio.h>
#include <string.h>

#define MAX_NUM 1000000 // 假設 a[i] 不超過 10^6

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[100];
    int count[MAX_NUM + 1] = {0}; // 記錄每個因數的出現次數
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // 計算 a[i] 的因數
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                count[j]++;
                if (j * j != a[i]) {
                    count[a[i] / j]++;
                }
            }
        }
    }
    
    int max_gcd = 1;
    for (int i = 1; i <= MAX_NUM; i++) {
        if (count[i] >= 2 && i > max_gcd) {
            max_gcd = i;
        }
    }
    
    printf("%d\n", max_gcd);
    return 0;
}



/*int main ()
{
    int a,b,c;
    int x,y;
    scanf("%i %i %i",&a,&b,&c);
    if (a-b == b-c)
    {
        x = a+(a-b);
        y = c-(b-c);
        printf("%i %i",x ,y);
    }
    else if (b/a == c/b)
    {
        x = a / (b/a);
        y = c * (c/b);
        printf("%i %i",x ,y);
    }
    
    return 0;
}*/