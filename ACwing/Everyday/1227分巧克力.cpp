/**
 * 整数二分
 **/ 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 100010;

vector<PII> w(N);

int n, k;

bool check(int mid) {
    LL count = 0;
    int x, y;
    for (auto& p : w) {
        x = p.first / mid;
        y = p.second / mid;
        count += (LL)x * y;
    }
    return count >= k;
}

int main() {
    cin >> n >> k;
    int x, y;
    for (int i = 0;i<n;i++) {
        cin >> x >> y;
        w.push_back({x, y});
    }
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = 1 + (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
