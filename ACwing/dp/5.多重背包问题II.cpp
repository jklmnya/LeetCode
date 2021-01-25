/**
 * 二进制优化
 * 思路：假设si = 100，将第i种物品分堆打包成新的物品，然后采用0/1背包做
 * 100拆分成：1，2，4，8，16，32，36
 **/ 

#include <iostream>

using namespace std;

const int N = 14000, M = 2010;    // > N * logs

int n, m;

int w[N], v[N];
int dp[N];

int main() {
    cin >> n >> m;
    int index = 0;      // 物品种类
    int weight, value, s;
    for (int i = 0;i<n;i++) {
        cin >> weight >> value >> s;
        int k = 1;
        // 划分物品
        while (k <= s) {
            index++;
            w[index] = weight * k;
            v[index] = value * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            index++;
            w[index] = weight * s;
            v[index] = value * s;
        }
    }
    n = index;
    // 0/1背包
    for (int i = 1;i<=n;i++) {
        for (int j = m;j>=w[i];j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
