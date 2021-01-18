/**
 * Trie字树 + 位运算
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3000000;

int childs[M][2], idx;
int nums[N];

int n;

// 建树
void insert(int num) {
    int node = 0;
    for (int i = 30;i>=0;i--) {
        // num >> i & 1 取num二进制下的第i位
        int index = (num >> i) & 1;
        // 不存在子节点，创建子节点
        if (childs[node][index] == 0) {
            childs[node][index] = ++idx;
        }
        node = childs[node][index];
    }
}

int find(int num) {
    int node = 0, res = 0;
    for (int i = 30;i>=0;i--) {
        int index = (num >> i) & 1;
        // XOR运算，优先考虑相反的位置有没有节点
        if (childs[node][!index]) {
            node = childs[node][!index];
            res += (1 << i);
        } else {
            node = childs[node][index];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> nums[i];
        insert(nums[i]);
    }
    int res = 0;
    for (int i = 0;i<n;i++) {
        res = max(res, find(nums[i]));
    }
    cout << res << endl;
    return 0;
}
