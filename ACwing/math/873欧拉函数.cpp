/**
 * 1 ~ N 中与 N 互质的数的个数被称为N的欧拉函数
 * N = (p1 ^ a1) * (p2 ^ a2) * ... * (pn ^ an)
 * ϕ(N) = N * ((p1 - 1) / p1) * ((p2 - 1) / p2) * ... * ((pn - 1) / pn)
 * 证明：容斥原理
 **/

#include <iostream>
#include <cmath>

using namespace std;

int n;

int main() {
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        int res = x;
        int stop = sqrt(x);
        for (int i = 2;i<=stop;i++) {
            if (x % i == 0) {
                res = res / i * (i - 1);    // 避免出现小数而截断
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) { res = res / x * (x - 1); } 
        cout << res << endl;
    }
    return 0;
}
