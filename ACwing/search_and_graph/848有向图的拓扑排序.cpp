/**
 * 有向五环图（拓扑图）
 * bfs
 **/
 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;

vector<vector<int>> g(N);

int inedge[N];                  // 入度数组

void sort() {
    queue<int> q;
    vector<int> res;            // 存放结果的数组
    for (int i = 1;i<=n;i++) {
        if (inedge[i] == 0) {
            q.push(i);          // 先遍历一边寻找入度为0的节点
        }
    }
    while(!q.empty()) {
        int point = q.front();
        res.push_back(point);
        q.pop();
        for (auto p : g[point]) {
            inedge[p]--;
            if (inedge[p] == 0) {
                q.push(p);
            }
        }
    }
    if (res.size() == n) {
        for (auto p : res) {
            cout << p << ' ';
        }
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0;i<m;i++) {
        cin >> x >> y;
        g[x].push_back(y);
        inedge[y]++;
    }
    sort();
    return 0;
}
