#include "headers/CoreMinial.h"

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) { return 1; }
        int res = 0, sum = 0, binary = 0;
        // INT_MAX = 2 * 31 - 1
        for (int i = 0;i<32;i++) {
            // get binary of each pos
            binary = (N >> i) & 1;
            sum += (binary << i);
            if (sum >= N) { break; }
            res += ((1 - binary) << i);
        }
        return res;
    }
};