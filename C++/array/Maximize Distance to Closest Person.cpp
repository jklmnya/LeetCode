#include "headers/CoreMinial.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        int res = INT_MIN;
        int lastOccupiedIndex = -1;
        int start = 0;
        int end = 0;
        // 正着扫，计算[0,0,0,1]
        for (int i = 0;i<size;i++) {
            if (seats[i] == 1) {
                lastOccupiedIndex = i;
                start = i + 1;
                res = i;
                break;
            }
        }
        // 反着扫，计算[1,0,0,0]
        for (int i = size - 1;i>=0;i--) {
            if (seats[i] == 1) {
                res = max(res, size - i - 1);
                end = i;
                break;
            }
        }
        // 扫描中间部分
        for (;start<=end;start++) {
            if (seats[start] == 1) {
                res = max(res, (start - lastOccupiedIndex) / 2);
                lastOccupiedIndex = start;
            }
        }
        return res;
    }
};