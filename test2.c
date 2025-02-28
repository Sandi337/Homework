#include <stdio.h>
#include <math.h>
    
int main() {
    int num1, num2;
    int i;

    scanf("%d %d", &num1, &num2);
    for(int i = num1; i<=num2; i++) 
    {
        int ans = num1/i;
    }
  
    printf("Sum: %d\n", num1 + num2);
  
    return 0;
  }