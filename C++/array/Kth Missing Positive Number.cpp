#include "headers/CoreMinial.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> vec(2005, false);
        for (auto& a : arr) {
            vec[a] = true;
        }
        int count = 0;
        for (int i = 1;i<vec.size();i++) {
            if (vec[i] == false && ++count == k) { 
                return i;
            }
        }
        return -1;
    }
};