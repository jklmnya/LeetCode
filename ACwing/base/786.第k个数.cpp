#include <iostream>

using namespace std;

const int N = 100010;

int n, k;
int vec[N];

int quickSort(int l, int r, int k) {
    if (l == r) return vec[r];
    int x = vec[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (vec[i] < x);
        do j--; while (vec[j] > x);
        if (i < j) swap(vec[i], vec[j]);
    }
    int sl = j - l + 1;
    if (k <= sl) return quickSort(l, j, k);
    return quickSort(j + 1, r, k - sl);
}

int main() {
    cin >> n >> k;
    for (int i = 0;i<n;i++) cin >> vec[i];
    cout << quickSort(0, n - 1, k) << endl;
    return 0;
}
