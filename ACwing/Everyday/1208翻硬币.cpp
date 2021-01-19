/**
 * 递推
 * 1. 对于第一个位置，要么翻要么不翻转；若对应位置不相同，则必须要翻，而且会对后面产生影响
 * 2. 第二个位置翻转不能影响第一个位置，只能影响下一个位置
 * 3. 以此类推
 **/ 
 
#include <iostream>
#include <string>

using namespace std;

string str1, str2;

void turn(int pos) {
    if (str1[pos] == '*') {
        str1[pos] = 'o';
    } else {
        str1[pos] = '*';
    }
}

int main() {
    cin >> str1 >> str2;
    int res = 0;
    for (int i = 0;i<str1.size() - 1;i++) {
        if (str1[i] != str2[i]) {
            res++;
            // 若第i位置不相同，则需反转第i和第i + 1位置
            turn(i);
            turn(i + 1);
        }
    }
    cout << res << endl;
    return 0;
}
