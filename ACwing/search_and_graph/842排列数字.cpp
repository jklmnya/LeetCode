/**
 * dfs + visited[]
 **/ 
 
#include <iostream>

using namespace std;

const int N = 10;

int n;
int res[N];
bool visited[N];    // 记录当前所有数字的访问情况

void dfs(int pos) {
    // 循环终止条件
    if (pos == n) { 
        for (int i = 0;i<n;i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1;i<=n;i++) {
        if (!visited[i]) {
            visited[i] = true;
            res[pos] = i;
            dfs(pos + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
