/**
 * Huffman + 堆
 **/ 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    int num;
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        cin >> num;
        q.push(num);
    }
    int res = 0;
    while (q.size() > 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        res += (x + y);
        q.push(x + y);
    }
    cout << res << endl;
    return 0;
}
