#include "headers/CoreMinial.h"

class Solution {
public:
    
    int maxValue;
    int minValue;
    
    vector<int> res;
    
    vector<int> sequentialDigits(int low, int high) {
        maxValue = high;
        minValue = low;
        for (int i = 9;i>=1;i--) {
            dfs(0, i, 0);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void dfs(int index, int value, int cur) {
        if (cur >= minValue && cur <= maxValue) {
            res.push_back(cur);
        }
        if (value <= 0) { return; }
        cur += (value * pow(10, index));
        if (cur > maxValue) { return; }
        dfs(index + 1, value - 1, cur);
    }
};