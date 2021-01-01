#include "headers/CoreMinial.h"

/**
 *  nums[i] —— 代表以i为结尾的连续子数组的最大的和
 *  动态转移方程 —— num[i] = max(nums[i], nums[i] + nums[i - 1])
 *  要么自身最大，要么前面的加上自身最大
 **/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1;i<nums.size();i++) {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            res = max(res, nums[i]);
        }
        return res;
    }
};