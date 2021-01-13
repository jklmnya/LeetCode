/**
 *  gcd(a, b) = gcd(b, a % b)
 *  gcd(a, 0) = a
 **/
 
#include <iostream>

using namespace std;

int count;

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main() {
    cin >> count;
    int a, b;
    while (count--) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
