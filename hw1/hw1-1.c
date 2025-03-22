#include <stdio.h>
#include <math.h>
    
int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    for(int i = num1 +1; i > num1; i++)
    {
        if (i%num1 == 0)
        {
            printf("%d %d\n",num1, i);
            break; 
        }
    }
    return 0;
  }