#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;
    int z;
    //double y;
    
    //sol 1 
    double ans = round((x * y) * pow(10, z)) / pow(10, z);
    printf("%.lf\n",ans);

    //sol 2 
    //printf("%.*lf\n",z,x * y);

    // scanf("%lf %lf %d",&x,&y,&z);
    // double result = x * y;
    // double point = pow(10,z);//10的z次方
    // result = round(result*point)/point;
    // printf("%.*lf\n",z,result);

}