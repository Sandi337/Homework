#include <stdio.h>
#include <string.h>

int T;
int is_equivalent(char *a ,char*b ,int len);

int main (){
    char a[1000],b[1000];
    scanf("%d",&T);
    while(T--){
        scanf("%s",&a);
        scanf("%s",&b);
        int len = strlen(a);
        if (strlen(a) != strlen(b)) {
            printf("No\n");
            continue;
        }
        int result = is_equivalent (a,b,len);
        printf ("%s",result);
        /*if (result ==){
        printf("Yes\n");
        }
        else {
        printf("No\n");
        }*/
    }
}


int is_equivalent(char *a ,char*b ,int len){
    if (strcmp(a, b) == 0) {
        return 1;
    }
    int mid = len / 2;
    while (mid > 0){
        if(mid % 2 == 1){
        int case_A = is_equivalent(a, b, mid) && is_equivalent(a + mid, b + mid, mid);
        int case_B = is_equivalent(a, b + mid, mid) && is_equivalent(a + mid, b, mid);
        return case_A || case_B;
        }  
        mid /=2;
    }
    
}