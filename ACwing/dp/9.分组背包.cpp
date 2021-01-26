/**
 * dp[i][j] 代表从前i类物品中选出重量之和不超过j的方案数的最大值
 **/ 
 
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;

int s[N], w[N][N], v[N][N];
int dp[N];

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> s[i];
        for (int j = 0;j<s[i];j++) {
            cin >> w[i][j] >> v[i][j];
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = m;j>=0;j--) {
            for (int k = 0;k<s[i];k++) {
                if (j >= w[i][k]) {
                    dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
