/**
 * bfs + 邻接表 + 有向图
 **/ 
 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;

vector<vector<int>> g(N);   //邻接表

int dis[N];                 // 距离数组，dis[i]存放点i到1的距离
    
int bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        int distance = dis[pos];
        if (pos == n) { return distance; }
        for (int i = 0;i<g[pos].size();i++) {
            // 第一次搜索到i结点更新dis[i]的值，保证dis[i]最小
            if (dis[g[pos][i]] == -1) {
                q.push(g[pos][i]);
                dis[g[pos][i]] = distance + 1;
            }
        }
    }
    return -1;
}

int main() {
    int x, y;
    cin >> n >> m;
    for (int i = 0;i<m;i++) {
        cin >> x >> y;
        g[x].push_back(y);
        // g[y].push_back(x);
    }
    // 初始化dis数字,默认-1，不可到达
    for (int i = 1;i<=n;i++) {
        dis[i] = -1;
    }
    dis[1] = 0;
    cout << bfs(1) << endl;
    return 0;
}
