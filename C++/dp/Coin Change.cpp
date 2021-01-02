#include "headers/CoreMinial.h"

/**
 *  dp[i] = min(dp[i - coin] + 1, dp[i])  dp[i] 代表到i状态所需的最小零钱数
 *  dp[i]可由dp[i - coin]加一个coin数目的零钱得到
 *  边界条件dp[0] = 0
 **/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1;i<=amount;i++) {
            for (auto& coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                } 
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};