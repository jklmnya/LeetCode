/**
 * 差分 
 * 假定b[]是a[]数组的差分数组，则对b数组求前缀和就可以得到a数组
 * a1 = b1， a2 = b1 + b2， a3 = b1 + b2 + b3, ...
 * 在a数组的l和r之间插入一个数c等价于bl + c, b(r + 1) - c
 **/ 
 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int b[N];

int main() {
    cin >> n >> m;
    int num;
    for (int i = 1;i<=n;i++) {
        cin >> num;
        b[i] += num;
        b[i + 1] -= num;
    }
    int l, r, c;
    while (m--) {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1;i<=n;i++) {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
    return 0;
}
