/**
 * bfs：广度优先，queue
 **/
 
#include <iostream>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 22;

int n, m;
char f[N][N];

int bfs(int sx, int sy) {
    queue<PII> q;
    int res = 0;
    q.push({sx, sy});
    f[sx][sy] = '#';
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // 方向变化量
    while (!q.empty()) {
        auto point = q.front();
        res++;
        q.pop();
        for (int i = 0;i<4;i++) {
            int x = point.x + dx[i], y = point.y + dy[i];
            // 判断是否越界或者不可以被访问
            if (x < 0 || x >= m || y < 0 || y >= n || f[x][y] != '.') { continue; }
            q.push({x, y});
            f[x][y] = '#';  // 修改当前坐标已被访问
        }
    }
    return res;
}

int main() {
    while (cin >> n >> m, n || m) {
        int x, y;
        for (int i = 0;i<m;i++) {
            for (int j = 0;j<n;j++) {
                cin >> f[i][j];
                if (f[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        cout << bfs(x, y) << endl;
    }
    return 0;
}
