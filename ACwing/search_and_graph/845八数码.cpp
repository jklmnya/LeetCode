/**
 * bfs
 * 1. 将3*3的矩阵转换为字符串
 * 2. 使用map存放每种状态相对于初始状态所需要变化的步骤
 **/ 
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

int bfs(string start) {
    string end = "12345678x";   // 终止状态
    queue<string> q;
    q.push(start);
    unordered_map<string, int> dis;
    dis[start] = 0;             // 初始状态的距离为0
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        int distance = dis[cur];
        if (cur == end) { return distance; }    // 判断当前是否为最终状态
        int pos = cur.find('x');    // 找出x在string中的位置
        for (int i = 0;i<4;i++) {
            // 将一维的坐标转化为二维下的坐标
            int x = (pos / 3) + dx[i], y = (pos % 3) + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                swap(cur[pos], cur[3 * x + y]);     // 变化x的位置
                if (!dis.count(cur)) {              // 判断状态是否已经存在于dis中
                    dis[cur] = distance + 1;
                    q.push(cur);
                }
                swap(cur[pos], cur[3 * x + y]);     // 恢复当前状态
            }
        }
    }
    return -1;
}

int main() {
    string start = "";
    char ch;
    for (int i = 0;i<9;i++) {
        cin >> ch;
        start += ch;
    }
    cout << bfs(start) << endl;
    return 0;
}
