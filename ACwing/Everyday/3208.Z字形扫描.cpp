#include <iostream>

using namespace std;

const int N = 1002;

int n;
int m[N][N];

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0;i<=2 * n;i++) {
        if (i % 2 == 0) {
            for (int j = 0;j<=i;j++) {
                if (m[i - j][j]) {
                    cout << m[i - j][j] << ' ';
                }
            }       
        } else {
            for (int j = i;j>=0;j--) {
                if (m[i - j][j]) {
                    cout << m[i - j][j] << ' ';
                }
            }
        }
    }
    return 0;
}
