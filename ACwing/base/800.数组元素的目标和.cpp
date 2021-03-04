#include <iostream>

using namespace std;

const int N = 100010;

int n, m, x;

int a[N], b[N];

/**
 * 利用单调性
 * i增加时，j只能减少
 **/
 
int main() {
    cin >> n >> m >> x;
    int num;
    for (int i = 0;i<n;i++) cin >> a[i];
    for (int j = 0;j<m;j++) cin >> b[j];
    for (int i = 0, j = m - 1;i<n;i++) {
        while (j>=0 && a[i] + b[j] > x) {
            j--;
        }
        if (a[i] + b[j] == x) {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}
