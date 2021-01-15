/**
 * dfs
 **/
 
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, res = N;

vector<vector<int>> g(N);

bool visited[N];            // 保存该节点是否已被访问的数组

// 返回以start为根结点的子树的结点总数
int dfs(int start) {
    int sum = 1;
    int maxValue = 0;       // 删除该节点后剩余最大联通块的大小
    visited[start] = true;
    for (int i = 0;i<g[start].size();i++) {
        if (!visited[g[start][i]]) {
            int value = dfs(g[start][i]);
            maxValue = max(maxValue, value);
            sum += value;   // 计算以start为根结点的子树的结点总数
        }
    }
    maxValue = max(maxValue, n - sum);
    res = min(res, maxValue);
    return sum;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0;i<n-1;i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << res << endl;
    return 0;
}
