#include <stdio.h>
#include <string.h>

#define MOD 1000000007

typedef struct _Mat {
    long long d[3][3];
} Mat;

Mat identity;

Mat matuml(Mat a, Mat b){
    Mat res;
    memset(res.d, 0,sizeof(res.d));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                res.d[i][j] = (res.d[i][j] +a.d[i][k] * b.d[k][j] % MOD) % MOD;
            }
        }
    }
    return res;
}

void init(){
    memset(identity.d, 0, sizeof(identity.d));
    long long _id[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    memcpy(identity.d, _id, sizeof(_id));
}

Mat fpw (Mat x, long long y){
    Mat res = identity;
    while (y){
        if(y%2 == 1) res = matuml(res, x);
        x = matuml(x, x);
        y /= 2;
    }
    return res;
}

int main(){
    int t;
    long long x;
    init();
    Mat T;
    memset(T.d, 0,sizeof(T.d));
    long long _T[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
    memcpy(T.d, _T, sizeof(_T));
    scanf("%d", &t);
    while (t--) {
    	scanf("%lld", &x);
        if (x == 1) {
            printf("%d\n", 1);
            continue;
        }
        if (x == 2) {
            printf("%d\n", 12);
            continue;
        }
        if (x == 3) {
            printf("%d\n", 13);
            continue;
        }
    	Mat res = fpw(T, x - 3);
    	printf("%lld\n", (res.d[0][0] * 13 + res.d[0][1]* 12 + res.d[0][2] * 1) % MOD);
    }
    return 0;
}