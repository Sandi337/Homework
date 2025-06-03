#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000

typedef struct{
    int a,b;
} Prod;
Prod p[MAX_N];

int cmp(const void *pl,const void *pr){
    Prod l = *(Prod *)pl;
    Prod r = *(Prod *)pr;
    return (l.a -l.b) - (r.a - r.b);
}
int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n; i++) scanf("%d", &p[i].a);
    for(int i = 0;i < n; i++) scanf("%d", &p[i].b);
    qsort(p, n,sizeof(Prod),cmp);
    //sizeof(p[0]) 會等價於 sizeof(Prod)，因為 p 是一個 Prod 型態的陣列，p[0] 是第一個 Prod 結構體。
    long long sum = 0;
    int i = 0;
    //因為已經按 $ (a_i - b_i) $ 排序，前 $ k $ 個產品的 $ (a_i - b_i) $ 是最小的，選擇它們使用方案 A 的損失最小。
    for(; i <k; ++i) sum += p[i].a;
    //後續產品中，若 $ a_i < b_i $，選擇方案 A
    for(; i <n && p[i].a < p[i].b; ++i) sum += p[i].a;
    //由於第二階段的條件是 $ p[i].a < p[i].b $，若迴圈結束，則剩下的產品滿足 $ p[i].a >= p[i].b $，此時選擇方案 B 更划算。
    for(; i <n; ++i) sum += p[i].b;
    printf("%lld\n", sum);
    return 0;
}
/*
ex: 
5 2
6 8 9 5 4
5 1 10 3 2

構建產品陣列並計算 $ (a_i - b_i) $：

產品 1：$ a_1 = 6 $，$ b_1 = 5 $，$ a_1 - b_1 = 1 $
產品 2：$ a_2 = 8 $，$ b_2 = 1 $，$ a_2 - b_2 = 7 $
產品 3：$ a_3 = 9 $，$ b_3 = 10 $，$ a_3 - b_3 = -1 $
產品 4：$ a_4 = 5 $，$ b_4 = 3 $，$ a_4 - b_4 = 2 $
產品 5：$ a_5 = 4 $，$ b_5 = 2 $，$ a_5 - b_5 = 2 $


按 $ (a_i - b_i) $ 排序：

$ (a_i - b_i) $ 值：$ [1, 7, -1, 2, 2] $
排序後：$ [-1, 1, 2, 2, 7] $
對應產品（按 $ (a_i - b_i) $ 排序後）：

產品 3：$ (a_3, b_3) = (9, 10) $，$ a_3 - b_3 = -1 $
產品 1：$ (a_1, b_1) = (6, 5) $，$ a_1 - b_1 = 1 $
產品 4：$ (a_4, b_4) = (5, 3) $，$ a_4 - b_4 = 2 $
產品 5：$ (a_5, b_5) = =$, $ a_5 - b_5 = 2 $
產品 2：$ (a_2, b_2) = (8, 1) $，$ a_2 - b_2 = 7 $

計算總花費：

$ k = 2 $，前 2 個產品必須選擇方案 A：

產品 3：$ a_3 = 9 $
產品 1：$ a_1 = 6 $
總和：$ 9 + 6 = 15 $


剩下的產品（產品 4、5、2）：

產品 4：$ a_4 = 5 $，$ b_4 = 3 $，$ a_4 \geq b_4 $，選擇 $ b_4 = 3 $
產品 5：$ a_5 = 4 $，$ b_5 = 2 $，$ a_5 \geq b_5 $，選擇 $ b_5 = 2 $
產品 2：$ a_2 = 8 $，$ b_2 = 1 $，$ a_2 \geq b_2 $，選擇 $ b_2 = 1 $


總和：$ 15 + 3 + 2 + 1 = 21 $
*/