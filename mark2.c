#include <stdio.h>
#include <math.h>

int main ()
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
}