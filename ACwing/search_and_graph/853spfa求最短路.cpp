/**
 * spfa
 * 只有松弛操作成功的点才有可能使得与之相邻的点的距离到原点的距离减小
 * 使用queue来维护松弛成功的点，然后遍历与之相连的点看是否可以松弛成功
 **/ 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;

int dist[N];
bool visited[N];
vector<vector<PII>> g(N);

int spfa() {
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int from = q.front();
        q.pop();
        visited[from] = false;
        for (int i = 0;i<g[from].size();i++) {
            int to = g[from][i].first, val = g[from][i].second;
            // 如果松弛成功,更新距离
            if (dist[to] > dist[from] + val) {
                dist[to] = dist[from] + val;
                // to没有在队列中,将to加入队列
                if (!visited[to]) {
                    q.push(to);
                    visited[to] = true;
                }
            }
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m;
    int x, y, z;
    for (int i = 0;i<m;i++) {
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
    for (int i = 1;i<=n;i++) {
        dist[i] = 0x3f3f3f3f;
    }
    dist[1] = 0;
    int res = spfa();
    if (res == -1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
