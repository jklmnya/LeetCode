#include "headers/CoreMinial.h"

/**
 *                                      Bit Manipulation
 * 
 *  Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *  Output: ["AAAAACCCCC","CCCCCAAAAA"]
 *  
 *  1. A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100 —— 发现只需要后三位就可以区分A，C，G，T
 *  2. 要求长度为10的重复子串 —— 使用int（32bit），只需要30位
 *  3. 如何让提取27位，使用&操作，mask = 0x7ffffff（00000111111111111111111111111111）
 *  4. 如何提取A的后3位，使用&操作，A & 7 —— 01000001 & 00000111 = 00000001
 *  5. cur = (cur << 3) | (s[i] & 7) —— 对A操作过后会得到 00000000000000000000000000000001
 *  6. AAAAACCCC操作过后 —— 001001001001001011011011011
 *  7. 使用int存可以节省空间
 *  8. 1 << 3  —— 0001 -> 1000
 **/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0;
        for (int i = 0;i<9;i++) { cur = (cur << 3) | (s[i] & 7); }
        for (int i = 9;i<s.size();i++) {
            cur = ((cur & 0x7ffffff) << 3) | (s[i] & 7);
            if (st.count(cur)) {
                res.insert(s.substr(i - 9, 10));
            } else {
                st.insert(cur);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};