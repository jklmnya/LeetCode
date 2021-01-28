/**
 * 差分
 **/ 

#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;

int b[N][N];

int main() {
    cin >> n >> m >> q;
    int num;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            cin >> num;
            b[i][j] += num;
            b[i][j + 1] -= num;
            b[i + 1][j] -= num;
            b[i + 1][j + 1] += num;
        }
    }
    int x1, x2, y1, y2, c;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x2 + 1][y1] -= c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }
    // 求前缀和
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i -1][j - 1];
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
