/**
 * 贪心 
 * 右端点排序；每次选择当前区间的右端点，看是否可以覆盖
 **/ 

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

struct range {
    int start;
    int end;
    bool operator< (const range& r) const {
        return end < r.end;
    }
} ranges[N];

int main() {
    cin >> n;
    int l, r;
    for (int i = 0;i<n;i++) {
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    int res = 0, right = -2e9;
    sort(ranges, ranges + n);
    for (int i = 0;i<n;i++) {
        // 若当前区间的左端点大于right，说明当前选点不能覆盖
        if (ranges[i].start > right) {
            res++;
            right = ranges[i].end;
        }
    }
    cout << res << endl;
    return 0;
}
