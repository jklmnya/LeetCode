#include "headers/CoreMinial.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int index = s.size() - 1;
        // handle ending space ' '
        while (index >= 0) {
            if (s[index] == ' ') { index--; }
            else { break; }
        }
        // judge if s equals ""/" "/"  "
        if (index >= 0) {
            for (int i = index;i>=0;i--) {
                if (s[i] != ' ') { res++; }
                else { break; }
            }   
        }
        return res;
    }
};