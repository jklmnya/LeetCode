/**
*   使用dx，dy数组来存储所有可能的偏移量（使用统一的判断条件来减少if判断的次数）
*   使用d来代表所走的方向
**/

#include <iostream>

using namespace std;

const int N = 101;
int n, m;

int f[N][N];

int main() {
    cin >> n >> m;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    for (int i = 1;i<=n*m;i++) {
        f[x][y] = i;
        int a = x + dx[d], b = y + dy[d];   // a，b暂存下次移动到的位置
        if (a < 0 || a >= n || b < 0 || b >= m || f[a][b]) {  // 边界条件判断，当前方向是否可走
            d = (d + 1) % 4;  // 不可走，更新d转换移动方向
        }
        x += dx[d], y += dy[d];   // 更新x，y
    }
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
