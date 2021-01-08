#include "headers/CoreMinial.h"

/**
 *  dp[i] —— 代表前i个字符是否可以被wordDict里面的word所表示
 *  eg. leetcode
 *         l  e  e  t  c  o  d  e
 *  dp  0  1  2  3  4  5  6  7  8
 * bool 1  0  0  0  1  0  0  0  1
 *  当dp['t'] = 1 && code存在于wordDict中时，将dp['e']置为true
 *  最后返回dp[‘e']    
 **/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1;i<dp.size();i++) {
            for (int j = 0;j<=i;j++) {
                string str = s.substr(j, i - j);
                if (dp[j] && us.count(str)) {
                    dp[i] = true;
                }
            }
        }
        return dp[dp.size() - 1];
    }
};
