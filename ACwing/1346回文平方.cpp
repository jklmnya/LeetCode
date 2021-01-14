/**
 * 将10进制转化为b进制：短除法
 * 将b进制转化为10进制：定义/秦九韶算法
 * eg: （1441）五进制 -> 1*(5^3) + 4*(5^2) + 4*(5^1) + 1*(5^0) -> ((1*5 + 4)*5 + 4)*5 + 1
 **/  
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 余数小于10，直接返回；大于10转化为字母
char get(int n) {
    if (n <= 9) { return n + '0'; }
    else { return n - 10 + 'A'; }
}

// 短除法
string base(int n, int b) {
    string num = "";
    while (n) {
        num += get(n % b);
        n /= b;
    }
    reverse(num.begin(), num.end());
    return num;
}

// 判断是否回文
bool check(string num) {
    int start = 0, end = num.size() - 1;
    while (start < end) {
        if (num[start] != num[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    int b;
    cin >> b;
    for (int i = 1;i<=300;i++) {
        string num = base(i * i, b);
        if (check(num)) {
            cout << base(i, b) << ' ' << num << endl;
        }
    }
    return 0;
}
