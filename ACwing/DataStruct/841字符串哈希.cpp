/**
 * 字符串哈希：快速算出字符串中某一段子串的哈希
 * 1. 计算出字符串所有前缀的哈希（将字符串看作是p进制的数，哈希值的对应的十进制数）
 * 1.1 p一般取131，13331；mod一般取2^64（存放在unsigned long long 溢出相当于取模）
 * 2. l - r 的哈希值 = h[r] - h[l - 1] * p ^ (r - l + 1)
 **/ 
 
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;

string str;

ULL h[N], p[N]; // h[]存放字符串前缀的哈希值，h[0] = 0；p[]存放预处理p^k的结果，p[0] = 1

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m;
    cin >> str;
    p[0] = 1;
    // 预处理p，h数组
    for (int i = 1;i<=n;i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i - 1];
    }
    int l1, l2, r1, r2;
    while (m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
