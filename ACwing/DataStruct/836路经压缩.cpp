/**
 * 并查集 + 路径压缩
 **/ 
 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int f[N];   // 当前结点的父亲节点

// 寻找当前节点的父亲节点 + 路径压缩(将树压缩成高度为2)
int find(int node) {
    if (f[node] != node) {
        f[node] = find(f[node]);
    }
    return f[node];
}

int main() {
    cin >> n >> m;
    // 初始化父亲节点数组，每个节点的父亲初始化为自身
    for (int i = 1;i<=n;i++) { f[i] = i; }
    char op;
    int x, y;
    for (int i = 0;i<m;i++) {
        cin >> op >> x >> y;
        // cout << op << endl;
        if (op == 'M') {
           f[find(x)] = find(y);
        } else {
            if (find(x) == find(y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
