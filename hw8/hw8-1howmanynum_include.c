#include <stdio.h>
#include <stdlib.h>

#define max 100005
int n,q,x;
int a[max];

int lower_bound(int *a, int n, int x){
    int l = 0, r = n;
    while(l < r){
        int mid = (l+r) /2;
        if(a[mid] < x) l = mid +1;
        else r = mid;
    } return r;
}

int upper_bound(int *a, int n, int x){
    int l = 0, r = n;
    while(l < r){
        int mid = (l+r) /2;
        if(a[mid] <= x) l = mid +1;
        else r = mid;
    } return r;
}

int compare_less(const void * pl, const void * pr)
{
   int l = *(int *) pl;
   int r = *(int *) pr;

   if (l > r) return 1;
   if (l < r) return -1;
   return 0;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), compare_less);
    scanf("%d",&q);
    while(q--) {
        scanf("%d", &x);
        int l = lower_bound(a , n ,x);
        int r = upper_bound(a , n ,x);
        printf("%d\n",r - l);
    }
    return 0;
}