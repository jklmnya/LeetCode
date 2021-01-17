/**
 * 并查集 + 路经压缩 + cnt[]（维护每个树中节点的个数）
 **/ 

#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int n, m;

int f[N], cnt[N];  // f[]当前结点父亲节点的下标，cnt[]当前结点所在集合节点的个数（只维护根结点即可）

int find(int node) {
    if (node != f[node]) {
        f[node] = find(f[node]);
    }
    return f[node];
}

int main() {
    cin >> n >> m;
    // 初始化f[],cnt[]数组
    for (int i = 1;i<=n;i++) {
        f[i] = i;
        cnt[i] = 1;
    }
    string op;
    int x, y;
    while (m--) {
        cin >> op;
        // cout << op << endl;
        if (op == "C") {
            cin >> x >> y;
            if (find(x) != find(y)) {
                // 如果x和y不在同一个集合中，将x所在集合合并到y所在集合
                cnt[find(y)] += cnt[find(x)];
                f[find(x)] = find(y);           
            }
        } else if (op == "Q1") {
            cin >> x >> y;
            if (find(x) == find(y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cin >> x;
            cout << cnt[find(x)] << endl;
        }
    }
    return 0;
}
