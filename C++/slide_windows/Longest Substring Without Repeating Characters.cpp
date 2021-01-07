#include "headers/CoreMinial.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0, end = 0;
        map<char, int> mapper;
        while (end < s.size()) {
            if (mapper[s[end]] >= 1) {
                res = max(res, getCount(mapper));
                while (start < end) {
                    if (s[start] == s[end]) {
                        start++;
                        break;
                    } else {
                        mapper[s[start]] = 0;
                    }
                    start++;
                }
            } else {
                mapper[s[end]]++;
            }
            end++;
        }
        res = max(res, getCount(mapper));
        return res;
    }
    
    int getCount(map<char, int>& mapper) {
        int count = 0;
        for (auto& ma : mapper) {
            if (ma.second == 1) {
                count++;
            }
        }
        return count;
    }
};