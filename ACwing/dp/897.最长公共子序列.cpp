/**
 * dp[i, j] 代表A字符串中前i个元素，B字符串中前j个元素的公共子序列的最大值（不一定包含第i，第j个元素）
 * dp[i, j] 可以划分为包含i，j；包含i，不包含j；不包含i，包含j；不包含i，j
 * 包含i，j -> dp[i - 1][j - 1] + 1
 * 不包含i，j -> dp[i - 1][j - 1]
 * 不包含i，包含j -> dp[i - 1][j](不包含i，包含j是dp[i][j]的子集)
 **/ 

#include <iostream>
#include <string>

using namespace std;

const int N = 1010;

int n, m;

int dp[N][N];

int main() {
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
