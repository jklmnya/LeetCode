#include "headers/CoreMinial.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0;i<nums.size();i++) {
            int start = nums[i];
            string str = to_string(start);
            while (i + 1 < nums.size() && ((nums[i+1]>>31) + (nums[i]>>31) != -1) && (nums[i+1] - nums[i] == 1)) { i++; }
            if (nums[i] != start) {
                str += "->";
                str += to_string(nums[i]);
            }
            res.push_back(str);
        }
        return res;
    }
};