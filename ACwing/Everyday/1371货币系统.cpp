/**
 * 完全背包
 * dp[i][j]代表使用前i种货币组成金额为m的方案数
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vi] + dp[i - 1][j - 2*vi] + dp[i - 1][j - 3*vi] + ...
 * dp[i][j - vi] =           dp[i - 1][j - vi] + dp[i - 1][j - 2*vi] +...
 * 
 * dp[i][j] = dp[i - 1][j] + dp[i][j - vi]
 **/ 

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 30, M = 10010;
int n, m;

int v[N];

LL dp[N][M];

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> v[i];
    }
    // 初始条件，不使用任何面额的货币组成0元的方案数为1
    dp[0][0] = 1;
    for (int i = 1;i<=n;i++) {
        for (int j = 0;j<=m;j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) {
                dp[i][j] += dp[i][j - v[i]];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

