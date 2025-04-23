#include <stdio.h>
#include <string.h>

/*int gcd(int a, int b){
    if (a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int gcd2(int a,int b){
    return (b==0) ? a : gcd2(b, a % b);
}*/
//三種方法等價，但相較之下gcd3的迭代比遞迴更節省記憶體


int n;
int a[1001];

int gcd3(int a, int b){
    while(b != 0){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
//比對兩個數值的gcd 會比比對三個還要大，在這題的情境中是要找大的gcd
void solve(){
    scanf("%d",&n);
    for (int i = 0;i <n ; i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int tmp = gcd3(a[i], a[j]);//比對兩個數值的gcd
            if(tmp > ans){
                ans = tmp;
            }
        }
    }
    printf("%d\n", ans);
}

int main (){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}