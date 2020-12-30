#include "headers/CoreMinial.h"

class Solution {
public:
    
    vector<vector<int>> res;
    int size;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        size = k;
        vector<int> vec;
        dfs(vec, 1, n, 0);
        return res;
    }
    
    void dfs(vector<int>& vec, int curr, int target, int sum) {
        if (vec.size() == size && sum == target) {
            res.push_back(vec);
            return;
        }
        for (int i = curr;i<=9;i++) {
            sum += i;
            if (sum > target) { return; }
            vec.push_back(i);
            dfs(vec, i+1,target, sum);
            sum -= i;
            vec.pop_back();
        }
    }
};