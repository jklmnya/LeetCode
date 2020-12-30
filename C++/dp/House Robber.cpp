#include "headers/CoreMinial.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) { return 0; }
        if (size == 1) { return nums[0]; }
        if (size == 2) { return max(nums[0], nums[1]); }
        // get max start num
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2;i<size;i++) {
            nums[i] = max(nums[i] + nums[i-2], nums[i-1]);
        }
        return nums[size-1];
    }
};