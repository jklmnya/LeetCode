/**
 * 前缀和：快速求出数组中某一段的和
 * l - r的和 = Sr - Sl-1
 **/ 
 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int nums[N], S[N];      // S前缀和数组

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> nums[i];
    }
    // 计算前缀和
    for (int i = 1;i<=n;i++) {
        S[i] = S[i - 1] + nums[i];
    }
    int l, r;
    while (m--) {
        cin >> l >> r;
        cout << S[r] - S[l - 1] << endl;
    }
    return 0;
}
