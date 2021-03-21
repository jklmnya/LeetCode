/**
  判断长度，数字的个数是否一样即可
**/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> vec(10, 0);
        int len = 1;
        int num = 1;
        while (N >= 10) {
            vec[N % 10]++;
            N /= 10;
            len++;
        }
        vec[N]++;
        while (num <= 1e9) {
            string str = to_string(num);
            if (str.size() != len) {   
                num <<= 1;
                continue;
            }
            vector<int> mapper(10, 0);
            for (auto ch : str) {
                mapper[ch - '0']++;
            }
            bool flag = true;
            for (int i = 0;i<10;i++) {
                if (vec[i] != mapper[i]) {
                    num <<= 1;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true; 
            }
        }
        return false;
    }
};
