/**
 * 朴素版Prim，O(n^2)
 **/ 

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 510;

int n, m;

vector<vector<int>> g(N, vector<int>(N, INT_MAX));

int dist[N];        // 结点到已确定结点集合的最短距离
bool visited[N];

int prim(int start) {
    visited[start] = true;
    int res = 0;
    for (int i = 0;i<n-1;i++) {
        int point = 0, minDis = INT_MAX;
        for (int j = 1;j<=n;j++) {
            if (!visited[j]) {
                dist[j] = min(dist[j], g[start][j]);
                if (dist[j] < minDis) {
                    point = j;
                    minDis = dist[j];
                }
            }
        }
        if (point == 0) {
            return -1;
        }
        res += dist[point];
        visited[point] = true;
        start = point;
    }
    return res;
}

int main() {
    cin >> n >> m;
    int x, y, z;
    // 因存在重边或者子环，最小生成树不能有环
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> z;
        if (x == y) { continue; }
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    for (int i = 1;i<=n;i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    int res = prim(1);
    if (res == -1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
