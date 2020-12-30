#include "headers/CoreMinial.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenNum = 0, oddNum = 0;
        for (auto& p : position) {
            if (p % 2 == 0) {
                evenNum++;
            } else {
                oddNum++;
            }
        }
        return min(evenNum, oddNum);
    }
};