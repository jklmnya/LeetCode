/**
 * 区间合并
 * 1. 所有区间按照左端点排序
 * 2. 从左到右遍历合并
 **/ 
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int n;

vector<PII> before;

int combine() {
    int i = 0;
    int res = 0;
    while (i < before.size()) {
        int end = before[i].second;
        for (i = i + 1;i<before.size();i++) {
            int x = before[i].first, y = before[i].second;
            if (x > end) {
                break;
            } else {
                end = max(end, y);
            }
        }
        res++;
    }
    return res;
}

int main() {
    cin >> n;
    int start, end;
    for (int i = 0;i<n;i++) {
        cin >> start >> end;
        before.push_back({start, end});
    }
    sort(before.begin(), before.end());
    cout << combine() << endl;
    return 0;
}
