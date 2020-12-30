#include "headers/CoreMinial.h"

class Solution {
public:
    
    // sort
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto& num : arr) { m[num]++; }
        // convert map to vector
        vector<pair<int, int>> vec(m.begin(), m.end());
        // sort vec by pair.second
        sort(vec.begin(), vec.end(), cmp);
        int count = 0;
        int threshold = arr.size() / 2;
        for (int i = 0;i<vec.size();i++) {
            count += vec[i].second;
            if (count >= threshold) {
                return i + 1;
            }
        }
        return -1;
    }
    
};