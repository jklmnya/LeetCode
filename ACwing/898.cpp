/**
* 给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，
* 一直走到底层，要求找出一条路径，使路径上的数字的和最大。
* 7
* 3 8
* 8 1 0 
* 2 7 4 4
* 4 5 2 6 5
* 自下而上dp
**/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 501;

int n;
int f[N][N]; 

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<=i;j++) {
            cin >> f[i][j];
        }
    }
    for (int i = n - 2;i>=0;i--) {
        n--;
        for (int j = 0;j<n;j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[0][0] <<endl;
    return 0;
}
