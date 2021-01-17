/**
 * 区间合并
 **/
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 5010;

int n;

LL res1, res2;

vector<PII> vec(N);

void combine() {
    int i = 0;
    int last_end = vec[0].first;
    while (i < n) {
        int start = vec[i].first, end = vec[i].second;
        res2 = max(res2, (LL)(start - last_end));
        for (i = i + 1;i<n;i++) {
            int x = vec[i].first, y = vec[i].second;
            if (x > end) {
                break;
            } else {
                end = max(end, y);
            }
        }
        last_end = end;
        res1 = max(res1, (LL)(end - start));
    }
}

int main() {
    cin >> n;
    int start, end;
    for (int i = 0;i<n;i++) {
        cin >> start >> end;
        vec[i].first = start;
        vec[i].second = end;
    }
    sort(vec.begin(), vec.begin() + n);
    combine();
    cout << res1 << ' ' << res2 << endl;
    return 0;
}
