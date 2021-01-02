#include "headers/CoreMinial.h"

/**
 *  dp[i] —— 代表以nums[i]为结尾的最大上升子数组的大小
 *  从nums[i-1]到nums[0]查看，若nums[j] < nums[i]，说明nums[i]可以放到nums[j]
 *  后面组成新的最大上升子数组
 * 
 *  最后遍历dp，找出最大值
 **/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1;i<nums.size();i++) {
            int maxV = INT_MIN;
            for (int j = i - 1;j>=0;j--) {
                if (nums[j] < nums[i]) {
                    maxV = max(maxV, dp[j]);
                }
            }
            dp[i] = max(dp[i], dp[i] + maxV);
        }
        int res = INT_MIN;
        for (auto& n : dp) {
            res = max(res, n);
        }
        return res;
    }
};