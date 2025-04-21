#include <stdio.h>
#include <string.h>

int n;
int count;
int board[14][14];

void placeOrRemove(int row, int col, int diff) {
    // 整行
    for (int j = 0; j < n; j++) board[row][j] += diff;
    // 整列
    for (int i = 0; i < n; i++) board[i][col] += diff;
    // 右下對角線
    for (int i = 0; row + i < n && col + i < n; i++) board[row + i][col + i] += diff;
    // 左下對角線
    for (int i = 0; row + i < n && col - i >= 0; i++) board[row + i][col - i] += diff;
    // 右上對角線
    for (int i = 0; row - i >= 0 && col + i < n; i++) board[row - i][col + i] += diff;
    // 左上對角線
    for (int i = 0; row - i >= 0 && col - i >= 0; i++) board[row - i][col - i] += diff;
}

void recursive(int row) {
    if (row == n) {
        ++count;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 0) {
            placeOrRemove(row, j, 1);
            recursive(row + 1);
            placeOrRemove(row, j, -1);
        }
    }
}

int main() {
    scanf("%d", &n);
    count = 0;
    memset(board, 0, sizeof(board));
    recursive(0);
    printf("%d\n", count);
    return 0;
}