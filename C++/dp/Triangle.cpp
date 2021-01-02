#include "headers/CoreMinial.h"

/**
 *  2
 *  3 4
 *  6 5 7
 * 
 *  dp[i][j] 代表从下往上到达i，j时的最短路径
 *  dp[i][j] += min(dp[i+1][j], dp[i+1][j+1])
 **/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        if (length >= 2) {
            for (int i = length - 2;i>=0;i--) {
                for (int j = 0;j<triangle[i].size();j++) {
                    triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
                }
            }
        }
        return triangle[0][0];
    }
};