#include "headers/CoreMinial.h"

class Solution {

public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (auto& vec : intervals) {
            if (vec[1] < newInterval[0] || vec[0] > newInterval[1]) {
                res.push_back(vec);
            } else {
                minValue = min(minValue, min(vec[0], newInterval[0]));
                maxValue = max(maxValue, max(vec[1], newInterval[1]));
            }
        }
        if (minValue != INT_MAX && maxValue != INT_MIN) {
            res.push_back(vector<int> {minValue, maxValue});
        } else {
            res.push_back(newInterval);
        }
        sort(res.begin(), res.end());
        return res;
    }
};