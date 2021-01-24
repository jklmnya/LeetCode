#include <iostream>

using namespace std;

const int N = 110;

int n;

int res[N][N];

int main() {
    for (int i = 0;i<100;i++) {
        res[i][i] = 1;
        for (int j = i + 1;j<100;j++) {
            res[i][j] = res[j][i] = res[i][j - 1] + 1;
        }
    }
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        } else {
            for (int i = 0;i<n;i++) {
                for (int j = 0;j<n;j++) {
                    cout << res[i][j] << ' ';
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
