/**
* 在一条数轴上有N家商店，它们的坐标分别为 A1~AN。
* 现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
* 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。
* 
* 贪心，排序后取中位数（最佳位置）
* ｜x - a| + |x - b| >= |a - b|，取等号时x在a，b之间
**/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) { cin >> a[i]; }
    sort(a, a + n);
    int res = 0;
    for (int i = 0;i<n;i++) {
        res += abs(a[i] - a[n / 2]);
    }
    cout << res <<endl;
    return 0;
}
