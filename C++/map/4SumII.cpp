#include "headers/CoreMinial.h"

/**
 *          Use HashMap to reduce time complexity to O(n^2)
 *          
 *          Use HashMap to store the sum of A+B
 * 
 **/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto& a : A) {
            for (auto& b : B) {
                m[a + b]++;
            }
        }
        for (auto& c : C) {
            for (auto& d : D) {
                res += m[-(c + d)];
            }
        }
        return res;
    }
};