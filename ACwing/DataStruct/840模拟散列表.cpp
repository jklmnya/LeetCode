/**
 * 哈希表 + 解决冲突方法 + 选取的mod值最好是大于题设条件的质数
 * 1. 开放寻址法
 * 2. 成组拉链法
 **/ 
 
#include <iostream>
#include <string>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

int n;

void insert(int num) {
    int index = (num % N + N) % N;  // 避免映射到负数
    e[idx] = num;
    ne[idx] = h[index];
    h[index] = idx++;
}

bool find(int num) {
    int index = (num % N + N) % N;
    for (int i = h[index];i!=-1;i = ne[i]) {
        if (e[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0;i<N;i++) {
        h[i] = -1;
    }
    string op;
    int num;
    while (n--) {
        cin >> op >> num;
        if (op == "I") {
            insert(num);
        } else {
            if (find(num)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
