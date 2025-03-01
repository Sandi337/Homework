#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    double y;
    int z;

    scanf("%lf %lf %d",&x,&y,&z);
    double result = x * y;
    double point = pow(10,z);
    result = round(result*point)/point;
    printf("%.*lf\n",z,result);

}