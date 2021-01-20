/**
 * 二分图的最大匹配：匈牙利算法
 * 1. 左面结点匹配右面节点
 * 2. 若左面结点相对应的右面节点之前匹配，查看右面对应的左节点是否有其他可以匹配的节点
 * 3. 以此类推
 **/ 
 
#include <iostream>
#include <vector>

using namespace std;

const int N = 510;

int n1, n2, m;

vector<vector<int>> g(N);
int match[N];       // 存放左节点对应的右节点的编号
bool visited[N];    // 右侧节点是否已经被访问

bool find(int left) {
    for (auto right : g[left]) {
        // 右边节点是否已经尝试过
        if (!visited[right]) {
            visited[right] = true;
            // 如果此时右侧节点还没有配对或者已经配对但对应的左侧节点可以找到其他右侧节点配对
            if (match[right] == 0 || find(match[right])) {
                match[right] = left;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    int x, y;
    while (m--) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    int res = 0;
    for (int i = 1;i<=n1;i++) {
        // 初始化visited,默认对于每个左侧节点，右侧节点都没有访问过
        for (int j = 1;j<=n2;j++) {
            visited[j] = false;
        }
        if (find(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
