#include <iostream>

using namespace std;

const int N = 15;

bool col[N], dg[2*N], udg[2*N];

int count, res[N];

int n;

void dfs(int row) {
    if (row == n) {
        count++;
        if (count <= 3) {
            for (int i = 0;i<n;i++) {
                cout << res[i] + 1 << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0;i<n;i++) {
        if (!col[i] && !dg[row + i] && !udg[n - row + i]) {
            col[i] = dg[row + i] = udg[n - row + i] = true;
            res[row] = i;
            dfs(row + 1);
            col[i] = dg[row + i] = udg[n - row + i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << count << endl;
    return 0;
}
