8/**
 * 浮点数二分
 * 直接难以求解，那就增加一个条件给定绳子长度x，看所有的绳子是否
 * 可以裁出>=给定数量的绳子，然后二分，直到一定精度为止
 * 保留n位小数，则L - R <= 1e-(n + 2)
 **/ 
 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int w[N];

bool check(double mid) {
    int count = 0;
    for (int i = 0;i<n;i++) {
        count += w[i] / mid;
    }
    return count >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0;i<n;i++) { cin >> w[i]; }
    double l = 0, r = 1e9;
    while (r - l > 1e-4) {
        double mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    //cout << l << endl;
    printf("%.2lf", r);
    return 0;
}
