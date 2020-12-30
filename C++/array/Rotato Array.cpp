#include "headers/CoreMinial.h"


/*

rotate the array to the right by k steps, where k is non-negative.

Original List                   : 1 2 3 4 5 6 7
After reversing all numbers     : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result

Time Complexity = O(n), Space Complexity = O(1)
*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= (nums.size());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};