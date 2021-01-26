/**
 * dp[i] 代表以i结尾的最长上升子序列,dp[i]可由前面的状态转移而来
 **/ 
 
#include <iostream>

using namespace std;

const int N = 1010;

int n;

int nums[N];
int dp[N];

int main() {
    cin >> n;
    int res = 1;
    for (int i = 0;i<n;i++) {
        cin >> nums[i];
        dp[i] = 1;
    }
    for (int i = 1;i<n;i++) {
        for (int j = i - 1;j>=0;j--) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
