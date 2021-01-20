/**
 * 二分图：不能存在奇数环，可通过二染色方法（相邻的节点不可能是同一种颜色）
 **/ 
 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;

vector<vector<int>> g(N);

int color[N];   // 保存每个节点染色的数组，0没有染色，1，2

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    int col = 1;
    int size = 1;
    while (q.size()) {
        for (int i = 0;i<size;i++) {
            int node = q.front();
            q.pop();
            color[node] = col;
            for (auto num : g[node]) {
                // 当前结点被染色，但与之相邻的节点染有相同的颜色，矛盾
                if (color[num]) {
                    if (color[num] == col) {
                        return false;
                    }
                } else {
                    // 该节点没有被染色，加入队列
                    q.push(num);
                }
            }
        }
        size = q.size();
        col = 3 - col;
    }
    return true;
}

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0;i<m;i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // 遍历n个节点，若每个节点没有被染色，执行bfs（图不一定是连通图）
    for (int i = 1;i<=n;i++) {
        if (!color[i]) {
            if (!bfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
