/**
 * bfs : 当每条边权重相同时，可以找到最短路径
 **/ 
 
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];

int bfs() {
    queue<PII> q;
    int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
    q.push({0, 0});
    g[0][0] = 2;
    while (!q.empty()) {
        auto point = q.front();
        q.pop();
        for (int i = 0;i<4;i++) {
            int a = point.first + dx[i], b = point.second + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0) {
                g[a][b] = g[point.first][point.second] + 1;
                q.push({a, b});
            }
        }
    }
    return g[n-1][m-1] - 2;
}

int main() {
    cin >> n >> m;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}
