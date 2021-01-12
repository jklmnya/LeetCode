/**
 * 思路：从i开始，如果i为质数，则删除从2*i开始所有i的倍数
 * eg：1，2，3，4，5，6，7，8，9，10，11，12
 * 2（质数）-> 删除4，6，8，10，12
 * 3（质数）-> 删除6，9，12
 * 5（质数）-> 删除10
 * 7（质数）
 * 11（质数）
 **/
 
 #include <iostream>
 
 using namespace std;
 
 int a;
 int n[1000010];    // n[i]代表i是否为质数
 int res;
 
 int main() {
     cin >> a;
     for (int i = 2;i<=a;i++) {
         if (!n[i]) {
             res++;
             for (int j = 2*i;j<=a;j+=i) {
                 n[j] = 1;
             }
         }
     }
     cout << res << endl;
     return 0;
 }
