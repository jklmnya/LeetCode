#include <iostream>
#include <cmath>

using namespace std;

/**
 *  判断一个数是不是质数（大于1）
 *  从2到sqrt(a)枚举判断是否能被整除即可
 *  O(sqrt(n))
 **/
 
int n;
int a;

bool isPrime(int a) {
    if (a < 2) { 
        return false;
    }
    int stop = sqrt(a);
    for (int i = 2;i<=stop;i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    while (n-- > 0) {
        cin >> a;
        if (isPrime(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
