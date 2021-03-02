#include <iostream>

using namespace std;

const int N = 100010;

int n;
int nums[N], count[N];      // count[]记录当前区间内各个数字的个数

/**
 * 固定i，看j往左能到什么位置
 **/
 
int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> nums[i];
    }
    int res = 0;
    for (int i = 0, j = 0;i<n;i++) {
        count[nums[i]]++;
        while (count[nums[i]] > 1) {
            count[nums[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
