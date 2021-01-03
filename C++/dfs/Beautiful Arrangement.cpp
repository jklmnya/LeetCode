#include "headers/CoreMinial.h"

class Solution {
public:
    int res = 0;
    
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        dfs(used, 1, n);
        return res;
    }
    
    void dfs(vector<bool>& used, int count, int& n) {
        if (count == n + 1) {
            res++;
            return;
        }
        for (int i = 1;i<=n;i++) {
            if (!used[i] && (count % i == 0 || i % count == 0)) {
                used[i] = true;
                dfs(used, count + 1, n);
                used[i] = false;
            }
        }
    }
};