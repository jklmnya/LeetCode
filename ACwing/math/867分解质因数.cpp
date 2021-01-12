/**
 * 性质：一个数最多只有一个大于根号n的质因数（反证法，若有两个根号n的质因数，两个质因数相乘
 * 就会大于n，矛盾）
 * eg. 6 = 2^1 * 3^1
 * 思路：先从2遍历到n，最后判断n是否大于1，若n大于1，则此时n为最后一个质因数
 **/
 
#include <iostream>
#include <cmath>

using namespace std;

int n;
int a;

void divide(int a) {
    int stop = sqrt(a);
    for (int i = 2;i<=stop;i++) {
        if (a % i == 0) {
            int count = 0;
            while (a % i == 0) {
                a /= i;
                count++;
            }
            cout << i << ' ' << count <<endl;
        }
    }
    // 判断最后一个可能大于sqrt(a)的质因数
    if (a > 1) {
        cout << a << ' ' << 1 << endl;
    }
    cout << endl;
}

int main() {
    cin >> n;
    while (n-- > 0) {
        cin >> a;
        divide(a);
    }
    return 0;
}
