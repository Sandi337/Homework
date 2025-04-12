#include <stdio.h>
#include <math.h>

long long x ,y ,ans;
int m;

int main(){

    scanf("%lld %lld %d", &x ,&y ,&m);

    if(y == 0){
        printf("%lld",1 % m);
        return 0;
    }

    ans = 1;
    x = x % m;
    
    while (y > 0){
        if(y % 2 == 1){
            ans = (ans * x) % m;//ans = 二進制對應1的模數
        }
        x = (x * x) % m;//x 會一直平方取模數(但二進制是0的位置不會累乘進ans)
        y /= 2;
    }
    printf("%lld",ans);
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