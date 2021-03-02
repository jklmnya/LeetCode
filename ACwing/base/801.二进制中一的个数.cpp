#include <iostream>

using namespace std;

int n;

int getOne(int num) {
    int count = 0;
    for (int i = 0;i<32;i++) {
        if ((num >> i & 1) == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int num;
    cin >> n;
    while (n--) {
        cin >> num;
        cout << getOne(num) << ' ';
    }
    return 0;
}
