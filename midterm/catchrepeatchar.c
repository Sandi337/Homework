#include <stdio.h>
#include <string.h>

int main(){
    //計算26個字母的重複，只要超過2次就可以跳出
    //這樣就不會因為字串過長造成MLE
    char ct[26];
    int n;
    
    scanf("%d",&n);
    memset(ct, 0, sizeof(ct));
    getchar(); //清除scanf後的換行符

    int has_repeated = 0;
    for(int i = 0;i < n-1;i++){
        char c = getchar();
        ct[c-'a']++;

        for (int j = 0; j < 26; j++) {
            if (ct[j] >= 2) {
                has_repeated = 1;
                break;
            }
        }
        if(has_repeated || n == 1){
            printf("I'm the god of Knuckles!\n");
            return 0;
        }
    }
    printf("Different makes perfect.\n");
    return 0;
}