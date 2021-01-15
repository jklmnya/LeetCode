/**
 * 数组模拟单链表
 * head：头结点，e[i]：下标为i的结点的数值，ne[i]：下标为i的结点的next指针，idx：目前已用的结点个数
 **/ 

#include <iostream>

using namespace std;

const int N = 100010;

int head, idx;

int e[N], ne[N];

// 初始化
void init() {
    head = -1, idx = 0;
}

// 头结点后插入
void insert_head(int val) {
    e[idx] = val;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 指定位置插入结点
void insert(int pos, int val) {
    e[idx] = val;
    ne[idx] = ne[pos];
    ne[pos] = idx;
    idx++;
}

// 删除结点
void erase(int pos) {
    if (pos == -1) {
        head = ne[head];
        return;
    }
    ne[pos] = ne[ne[pos]];
}

int main() {
    init();
    int count;
    cin >> count;
    while (count--) {
        char op;
        int pos, val;
        cin >> op;
        if (op == 'H') {
            cin >> val;
            insert_head(val);
        } else if (op == 'D') {
            cin >> pos;
            erase(pos - 1);
        } else {
            cin >> pos >> val;
            insert(pos - 1, val);
        }
    }
    for (int i = head;i!=-1;i = ne[i]) {
        cout << e[i] << ' ';
    }
    cout << endl;
    return 0;
}
