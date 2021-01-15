/**
 * 堆优化Dijkstra，O(mlogm）
 * C++ 优先队列默认大根堆 priority_queue<PII, vector<PII>, less<PII>> q;
 * 小根堆 priority_queue<PII, vector<PII>, greater<PII>> q;
 **/ 
 
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;

vector<vector<PII>> g(N);   // 邻接表,PII.second(结点的下标),PII.first(边的权重)
bool visited[N];
int dist[N];

int dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (q.size()) {
        PII p = q.top();        // 每次从堆顶拿出一个pair，O(1)
        q.pop();
        int point = p.second, val = p.first;
        if (visited[point]) { continue; }   // 判断该点是否被访问过
        visited[point] = true;
        for (int i = 0;i<g[point].size();i++) {
            int next = g[point][i].second, next_val = g[point][i].first;
            if (dist[next] > val + next_val) {  // 会存入一些冗余的pair，但不影响结果
                q.push({val + next_val, next}); // 插入堆顶，O(logm)
                dist[next] = val + next_val;
            }
        }
    }
    if (dist[n] == INT_MAX) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0;i<m;i++) {
        cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
    for (int i = 1;i<=n;i++) { dist[i] = INT_MAX; }
    dist[1] = 0;
    cout << dijkstra() << endl;
    return 0;
}
