/**
 * 
 * 
 **/
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int l, m;

vector<PII> before;

int combine() {
    int i = 0;
    int sum = 0;
    while (i < before.size()) {
        int start = before[i].first, end = before[i].second;
        for (i = i + 1;i<before.size();i++) {
            int x = before[i].first, y = before[i].second;
            if (x > end) {
                break;
            } else {
                end = max(end, y);
            }
        }
        sum += end - start + 1;
    }
    return sum;
}

int main() {
    cin >> l >> m;
    int start, end;
    for (int i = 0;i<m;i++) {
        cin >> start >> end;
        before.push_back({start, end});
    }
    sort(before.begin(), before.end());
    cout << (l + 1) - combine() << endl;
    return 0;
}
