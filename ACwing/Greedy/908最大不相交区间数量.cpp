/**
 * Greedy
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

struct range {
    int start, end;
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
    sort(ranges, ranges + n);
    int res = 0, right = -2e9;
    for (int i = 0;i<n;i++) {
        if (ranges[i].start > right) {
            res++;
            right = ranges[i].end;
        }
    }
    cout << res << endl;
    return 0;
}
