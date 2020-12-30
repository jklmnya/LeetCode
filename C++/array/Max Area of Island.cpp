#include "headers/CoreMinial.h"

class Solution {
public:
    
    int xMax = 0;
    int yMax = 0;
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        xMax = grid.size() - 1;
        yMax = grid[0].size() - 1;
        for (int i = 0;i<=xMax;i++) {
            for (int j = 0;j<=yMax;j++) {
                if (grid[i][j] == 1) {
                    res = max(res, getMaxArea(grid, i, j));
                }
            }
        }
        return res;
    }
    
    int getMaxArea(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x > xMax || y < 0 || y > yMax || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + getMaxArea(grid, x - 1, y) + getMaxArea(grid, x + 1, y) + getMaxArea(grid, x, y - 1) + getMaxArea(grid, x, y + 1);
    }
};