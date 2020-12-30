#include "headers/CoreMinial.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }
        int res = 0;
        int temp;
        // reverse_iter
        map<int, int>::reverse_iterator rit;
        for (rit = m.rbegin();rit!=m.rend();rit++) {
            if (k == 0) {
                if ((*rit).second > 1) {
                    res++; 
                }
            } else {
                temp = (*rit).first - k;
                if (m.find(temp) != m.end() && m[temp] > 0) {
                    res++;
                    m[temp] = 0;
                }
            } 
        }
        return res;
    }
};