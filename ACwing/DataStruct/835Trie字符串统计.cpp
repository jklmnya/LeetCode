/**
 * Trie字典树
 * childs[N][26], childs[i][26]代表节点i的26的子节点
 * cnt[i]，代表以节点i为结尾的单词的个数
 * idx，当前使用的节点的下标
 * i = 0代表根结点
 **/ 

#include<iostream>
#include <string>

using namespace std;

const int N = 100010;

int n;

int childs[N][26], cnt[N], idx;

void insert(string word) {
    // 初始化node为根结点
    int node = 0;
    for (auto ch : word) {
        // 将字符映射到数组下标
        int index = ch - 'a';
        // 判断node是否存在对应的子节点，若不存在，则插入
        if (!childs[node][index]) {
            childs[node][index] = ++idx;
        }
        // 让node成为对应子节点
        node = childs[node][index];
    }
    // 相应单词加一
    cnt[node]++;
}

int find(string word) {
    int node = 0;
    for (auto ch : word) {
        int index = ch - 'a';
        if (!childs[node][index]) {
            return 0;
        }
        node = childs[node][index];
    }
    return cnt[node];
}

int main() {
    cin >> n;
    string op, word;
    for (int i = 0;i<n;i++) {
        cin >> op >> word;
        if (op == "I") {
            insert(word);
        } else {
            cout << find(word) << endl;
        }
    }
    return 0;
}
