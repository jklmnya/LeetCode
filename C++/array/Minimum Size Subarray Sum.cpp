#include "headers/CoreMinial.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) { return 0; }
        if (size == 1) {
            if (nums[0] >= s) { return 1; }
            else { return 0; }
        }
        int start = 0, end = 0, res = INT_MAX;
        int sum = 0;
        while (end < size) {
            sum += nums[end];
            if (sum >= s) { 
                while (start <= end) {
                    if (sum - nums[start] >= s) {
                        sum -= nums[start++];
                    } else {
                        break;
                    }
                }
                res = min(res, end - start + 1); 
            }
            end++;
        }
        return res == INT_MAX ? 0 : res;
    }
};