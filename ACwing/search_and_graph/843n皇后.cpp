/**
 * dfs
 * 
 **/

#include <iostream>

using namespace std;

const int N = 10;

int n;
char res[N][N];
bool col[N], dg[N], udg[N];     // 列，主对角线，反对角线有没有放置皇后

// row:从0 -> n-1选择
void dfs(int row) {
    // 递归终止条件,每一行都放了一个皇后
    if (row == n) {
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<n;j++) {
                cout << res[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0;i<n;i++) {
        // 判断是否点(row，i)可以放皇后，dg[row + i]，udg[n - row + i]
        if (!col[i] && !dg[row + i] && !udg[n - row + i]) {
            res[row][i] = 'Q';
            col[i] = dg[row + i] = udg[n - row + i] = true;
            dfs(row + 1);
            col[i] = dg[row + i] = udg[n - row + i] = false;
            res[row][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    // 初始化res
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            res[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
