/**
 * greedy
 * 可以确定的是最后山峰的高度会落在[0,17], [1, 18], [2, 19]...[83, 100]这些区间，枚举即可
 **/ 

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;

int h[N];

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> h[i];
    }
    int res = 1e8;
    for (int i = 0;i<=83;i++) {
        int l = i, r = i + 17, cost = 0;
        for (int j = 0;j<n;j++) {
            if (h[j] < l) { cost += (l - h[j]) * (l - h[j]); }
            else if (h[j] > r) { cost += (h[j] - r) * (h[j] - r); }
        }
        res = min(res, cost);
    }
    cout << res << endl;
    return 0;
}
