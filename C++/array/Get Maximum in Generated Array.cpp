#include "headers/CoreMinial.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) { return n; }
        vector<int> vec(n + 2, 0);
        vec[0] = 0, vec[1] = 1;
        for (int i = 1;i<=n/2;i++) {
            vec[i*2] = vec[i];
            vec[i*2 + 1] = vec[i] + vec[i+1];
        }
        int res = 1;
        for (int i = 2;i<n + 1;i++) {
            res = max(res, vec[i]);
        }
        return res;
    }
};