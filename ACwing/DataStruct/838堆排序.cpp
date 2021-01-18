/**
 * 一维数组模拟堆
 * 1. 建堆 —— 先按顺序读入元素，再从(size/2 - 1)处执行down操作建堆，O(n)
 * 2. down,O(logn)
 * 3. 访问并删除堆顶元素，堆顶与堆尾元素交换，再对堆顶元素执行down操作
 **/ 
 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int heap[N], h_size;

void down(int index) {
    int pos = index;
    // 判断是否有左右子节点，比较值的大小然后交换，最后递归
    if (index * 2 <= h_size && heap[index * 2] < heap[pos]) { pos = index * 2; }
    if (index * 2 + 1 <= h_size && heap[index * 2 + 1] < heap[pos]) { pos = index * 2 + 1; }
    if (pos != index) {
        swap(heap[index], heap[pos]);
        down(pos);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> heap[i];
    }
    h_size = n;
    // 执行down操作初始化堆
    for (int i = h_size / 2;i>=1;i--) {
        down(i);
    }
    for (int i = 0;i<m;i++) {
        // 删除堆顶元素，用堆尾元素替换，再执行down(1)
        cout << heap[1] << ' ';
        heap[1] = heap[h_size];
        h_size--;
        down(1);
    }
    return 0;
}
