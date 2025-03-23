#include <stdio.h>
#include <string.h>

char s[2010];  // 字符串陣列，最大長度 2000

// 檢查 s[i:j+1] 是否是回文
int is_palindrome(int i, int j) {
    if (i == j) return 0;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    // 讀取字符串直到 EOF
    while (scanf("%s", s) != EOF) {
        int n = strlen(s);  // 字符串長度
        int count = 0;  // 回文子字符串數量

        // 枚舉所有子字符串
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (is_palindrome(i, j)) {
                    count++;
                }
            }
        }

        // 輸出結果
        printf("%d\n", count);
    }
    return 0;
}