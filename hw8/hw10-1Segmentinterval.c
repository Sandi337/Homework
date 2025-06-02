//這題會考 sorting
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct{
    double l,r;
} Interval;
Interval LR[MAX_N];

int n,q;

int compare_less(const void *a, const void *b){
    Interval *ia = (Interval*) a;
    Interval *ib = (Interval*) b;
    // if (ia-> l != ib ->l) return ia->l - ib -> l; ERROR!
    if(ia->l < ib ->l) return -1;
    if(ia->l > ib ->l) return 1;
    if(ia->r < ib ->r) return -1;
    if(ia->r > ib ->r) return 1;
    return 0;
}

void solve() {
    // 讀取輸入：n 表示總長度，q 表示區間數量
    scanf("%d%d", &n, &q);
    
    // 讀取 q 個區間，每個區間包含左端點 (l) 和右端點 (r)
    for (int i = 0; i < q; i++) {
        scanf("%lf%lf", &LR[i].l, &LR[i].r);
    }
    
    // 使用 qsort 對 LR 陣列中的 q 個區間進行排序
    // 排序依據 compare_less 函數，先按左端點 (l) 升序，若左端點相等則按右端點 (r) 升序
    // 這裡的 compare_less 使用 ia 和 ib 作為指向 LR 陣列中兩個 Interval 結構的指標
    // ia 和 ib 分別指向某兩個區間（如 LR[i] 和 LR[j]），用於比較它們的 l 和 r
    qsort(LR, q, sizeof(LR[0]), compare_less);
    
    // tol：記錄所有合併後區間的總長度
    // cur_l：當前合併區間的左端點
    // cur_r：當前合併區間的右端點
    double tol = 0, cur_l = 0, cur_r = 0;
    
    // 遍歷排序後的區間，進行區間合併
    for (int i = 0; i < q; i++) {
        // 如果當前區間的左端點大於當前合併區間的右端點，則前一個合併區間結束
        if (LR[i].l > cur_r) {
            // 將前一個合併區間的長度 (cur_r - cur_l) 加入總長度 tol
            tol += cur_r - cur_l;
            // 開始新的合併區間，將當前區間的左右端點設為新的 cur_l 和 cur_r
            cur_l = LR[i].l;
            cur_r = LR[i].r;
        }
        // 如果當前區間的左端點 <= cur_r，但右端點超出 cur_r，則擴展合併區間的右端點
        else if (LR[i].r > cur_r) {
            cur_r = LR[i].r;
        }
        // 如果當前區間完全被當前合併區間包含（LR[i].r <= cur_r），則無需更新
    }
    // 將最後一個合併區間的長度加入 tol
    tol += cur_r - cur_l;
    
    // 計算未被覆蓋的比例：(總長度 n - 合併區間總長度 tol) / n
    // 使用 %.6lf 格式化輸出，保留 6 位小數
    printf("%.6lf\n", ((double)n - tol) / n);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
}