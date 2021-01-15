/**
 * 朴素版Dijkstra
 * O(n^2)
 **/ 
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 510;

int n, m;

vector<vector<int>> g(N, vector<int>(N, INT_MAX));
int dist[N];
bool visited[N];

int dijkstra() {
    for (int i = 1;i<=n;i++) {
        int value = INT_MAX;
        int point;
        for (int j = 1;j<=n;j++) {
            if (!visited[j] && dist[j] < value) {
                point = j;
                value = dist[j];
            }
        }
        visited[point] = true;
        for (int i = 1;i<=n;i++) {
            if (g[point][i] != INT_MAX) {
                dist[i] = min(dist[i], dist[point] + g[point][i]);
            }
        }
    }
    if (dist[n] == INT_MAX) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m;
    // 初始化dist数组，默认INT_MAX（不可到达）
    for (int i = 1;i<=n;i++) {
        dist[i] = INT_MAX;
        g[i][i] = 0;
    }
    dist[1] = 0;
    int a, b, c;
    for (int i = 1;i<=m;i++) {
        cin >> a >> b >> c;
        // 防止子环或者重边，取最小值
        g[a][b] = min(c, g[a][b]);
    }
    cout << dijkstra() << endl;
    return 0;
}
