/**
 * 利用cnt数组来保存到当前结点的边的个数，若cnt[i] >= n说明经过n + 1个点
 * 说明存在负环
 **/
 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 2010;

int n, m;

bool visited[N];
int dist[N], cnt[N];

vector<vector<PII>> g(N);

bool spfa() {
    queue<int> q;
    for (int i = 1;i<=n;i++) { 
        q.push(i); 
        visited[i] = true;
    }
    while (q.size()) {
        int from = q.front();
        q.pop();
        visited[from] = false;
        for (int i = 0;i<g[from].size();i++) {
            int to = g[from][i].first, val = g[from][i].second;
            if (dist[to] > dist[from] + val) {
                dist[to] = dist[from] + val;
                cnt[to] = cnt[from] + 1;
                if (cnt[to] >= n) {
                    return true;
                }
                if (!visited[to]) {
                    q.push(to);
                    visited[to] = true;
                }
            }
        }
    }
    return false;
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
    if (spfa()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
