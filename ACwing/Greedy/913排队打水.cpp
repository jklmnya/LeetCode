/**
 * 参考最短作业优先算法（使得排队等到时间最小）
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

int need[N];

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> need[i];
    }
    sort(need, need + n);
    long long res = 0;
    for (int i = 0;i<n-1;i++) {
        res += need[i] * (n - 1 - i);
    }
    cout << res << endl;
    return 0;
}
