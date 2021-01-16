/**
 * Bellman-Ford（存在负环，且有边数限制）
 * 存在负权回路有可能导致1-n的最短路径不存在
 *    1    2     3
 * 1 --> 2 --> 3 --> 4
 *       ↑     | 
 *       | -4  |    
 *       4 ——---    
 * 此图中1->4的最短路径不存在，因为中间存在负环
 * 
 * 思路：
 * 1. 循环k次
 * 2. 每次遍历所有边，dist[y] = min(dist[y], backup[x] + z);
 * 3. 注意使用backup更新,防止出现串联影响
 **/ 
 
#include <iostream>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;

int dist[N], backup[N];

struct edge {
    int x, y, z;
} edges[M];

int bellman_ford() {
    for (int i = 0;i<k;i++) {
        int x, y, z;
        // 备份dist
        for (int j = 1;j<=n;j++) {
            backup[j] = dist[j];
        }
        for (int j = 0;j<m;j++) {
            x = edges[j].x, y = edges[j].y, z = edges[j].z;
            dist[y] = min(dist[y], backup[x] + z);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m >> k;
    int x, y, z;
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    // 初始化dist
    for (int i = 1;i<=n;i++) {
        dist[i] = 0x3f3f3f3f;
    }
    dist[1] = 0;
    int res = bellman_ford();
    if (res == -1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
