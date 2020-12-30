#include "headers/CoreMinial.h"

/**
 * 
 *      Greedy + Two Pointer
 *      sort tokens in ascend
 *      if can get score, then we let P -= tokens[start]; score++
 *      if can not get score, then we let P += tokens[end]; score--
 * 
 **/

class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int P) {
        int res = 0;
        sort(tokens.begin(), tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        while (start <= end) {
            if (P >= tokens[start]) {
                P -= tokens[start++];
                res++;
            } else {
                if (res > 0 && start != end) {
                    P += tokens[end--];
                    res--;
                } else {
                    return res;
                }
            } 
        }
        return res;
    }

};