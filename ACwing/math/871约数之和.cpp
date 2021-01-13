/**
 * 思路: 先将所有数的因数以及指数存在map中
 * x = p1^a1 * p2^a2 * .. * pn^an
 * 则所有数字的约数之和为(p1^0 + p1^1 + ... + p1^a1) ... (pn^0 + pn^1 + ... + pn^an)
 **/
 
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main() {
    int count;
    unordered_map<int, int> mapper;
    LL res = 1;
    cin >> count;
    while (count--) {
        int x;
        cin >> x;
        int stop = sqrt(x);
        for (int i = 2;i<=stop;i++) {
            if (x % i == 0) {
                int n = 0;  // x因数i的指数
                while (x % i == 0) {
                    x /= i;
                    n++;
                }
                mapper[i] += n;
            }
        }
        if (x > 1) { mapper[x]++; }
    }
    for (auto& p : mapper) {
        LL n = 1;
        int x = p.first, y = p.second;
        while (y > 0) {
            n = (n * x + 1) % mod;
            y--;
        }
        res = res * n % mod;
    }
    cout << res << endl;
    return 0;
}
