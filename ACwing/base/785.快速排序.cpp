#include <iostream>

using namespace std;

const int N = 100010;

int n;

int vec[N];

void quickSort(int start, int end) {
    if (start >= end) return;
    int x = vec[(start + end) / 2], i = start - 1, j = end + 1;
    while (i < j) {
        do i++; while (vec[i] < x);
        do j--; while (vec[j] > x);
        if (i < j) swap(vec[i], vec[j]);
    }
    quickSort(start, j);
    quickSort(j + 1, end);
}

int main() {
    scanf("%d", &n);
    for (int i = 0;i<n;i++) scanf("%d", &vec[i]);
    quickSort(0, n - 1);
    for (int i = 0;i<n;i++) printf("%d ", vec[i]);
    return 0;
}
