/**
 * dp 完全背包
 * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i], dp[i - 1][j - 2*v[i]] + 2*w[i], ..., dp[i][j - k*v[i]] + k*w[i])
 * dp[i][j - v[i]] = max(       dp[i - 1][j-v[i]]       ,   dp[i - 1][j - 2*v[i]] + w[i],  ...,       )
 * 
 * dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i])
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;

int w[N], v[N], f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 0;j<=m;j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] = max(f[i][j], f[i][j - w[i]] + v[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
