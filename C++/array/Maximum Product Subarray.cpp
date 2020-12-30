#include "headers/CoreMinial.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) { return 0; }
        int res = nums[0];
        // find out the maxValue, minValue
        int maxValue = nums[0];
        int minValue = nums[0];
        for (int i = 1;i<size;i++) {
            int t1 = maxValue * nums[i];
            int t2 = minValue * nums[i];
            maxValue = max(max(t1, t2), nums[i]);
            minValue = min(min(t1, t2), nums[i]);
            res = max(res, maxValue);
        }
        return res;
    }
};