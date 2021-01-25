/**
 * 朴素版
 * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vi] + wi, dp[i - 1][j - 2*vi] + 2*wi, ...)
 * 集合划分——选0，1，2，3，...，个第i个元素
 **/ 
 
#include <iostream>

using namespace std;

const int N = 110;

int n, m;

int v[N], w[N], s[N];
int dp[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 0;j<=m;j++) {
            for (int k = 0;k<=s[i];k++) {
                if (j >= k*w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k*w[i]] + k*v[i]);
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
 
