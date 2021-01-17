/**
 * Kruskal:对每条边按照权值排序 + 并查集
 * 加边相当于集合合并的操作，最后看是否加入了n-1条边
 **/ 

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;

int f[N];

struct edge {
    int x, y, w;
    // 重载操作符<，实现升序排序
    bool operator<(const edge& e) {
        return w < e.w;
    }
} edges[N * 2];

int find(int node) {
    if (node != f[node]) {
        f[node] = find(f[node]);
    }
    return f[node];
}

int kruskal() {
    // 先按照权值对边升序排序
    sort(edges, edges + m);
    int cnt = 0, res = 0;   // cnt已加入边的个数
    for (int i = 0;i<m;i++) {
        int x = edges[i].x, y = edges[i].y, w = edges[i].w;
        if (find(x) != find(y)) {   // 如果x，y不在同一集合中，合并x，y
            cnt++;
            res += w;
            f[find(x)] = find(y);
        }
    }
    return cnt == n - 1 ? res : -1;
}

int main() {
    cin >> n >> m;
    int x, y, z;
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    for (int i = 1;i<=n;i++) {
        f[i] = i;
    }
    int res = kruskal();
    if (res == -1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
