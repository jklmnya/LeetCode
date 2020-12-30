#include "headers/CoreMinial.h"

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // dx, dy --> delta movement in x, y direction
        int x = 0, y = 0, dx = 0, dy = 1;
        int temp;
        // loop 4 times
        for (int i = 0;i<=3;i++) {
            for (auto ch : instructions) {
                if (ch == 'G') {
                    x += dx;
                    y += dy;
                } else if (ch == 'L') {
                    temp = dx;
                    dx = -dy;
                    dy = temp;
                } else {
                    temp = dx;
                    dx = dy;
                    dy = -temp;
                }
            }
        }
        return (x == 0 && y == 0);
    }
};