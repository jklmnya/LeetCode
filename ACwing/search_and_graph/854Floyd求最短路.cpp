/**
 * Floyd, O(n^3)
 * for (int k = 1;k<=n;k++) {
     for (int i = 1;i<=n;i++) {
         for (int j = 1;j<=n;j++) {
             d[i][j] = min(d[i][j], d[i][k] + d[k][j])
         }
     }
 }
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210;

int n, m, q;

int dist[N][N];

void floyd() {
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (i != j) {
                dist[i][j] = 0x3f3f3f3f;
            }
        }
    }
    int x, y, w;
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> w;
        // 存在重边，取最小值
        dist[x][y] = min(dist[x][y], w);
    }
    floyd();
    for (int i = 0;i<q;i++) {
        cin >> x >> y;
        if (dist[x][y] > 0x3f3f3f3f / 2) {
            cout << "impossible" << endl;
        } else {
            cout << dist[x][y] << endl;
        }
    }
    return 0;
}
