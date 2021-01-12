/**
 * 思路：对一个数分解质因数
 * eg：x = a1^k1 * a2^k2 ... * an^kn -> 该数的约数个数为(k1 + 1)(k2 + 1)..(kn + 1)
 * 该题思路：对每一个数分解质因数，将结果保存在hashmap中，相同的因数指数相加即可
 **/ 
 
 #include <iostream>
 #include <unordered_map>
 #include <cmath>
 
 using namespace std;
 
 const int mod = 1e9 + 7;
 typedef long long LL;
 
 int main() {
     int count;
     unordered_map<int, int> primes;
     cin >> count;
     while (count--) {
         int n;
         cin >> n;
         int stop = sqrt(n);
         for (int i = 2;i<=stop;i++) {
             if (n % i == 0) {
                 int num = 0;
                 while (n % i == 0) {
                     n /= i ;
                     num++;
                 }
                 primes[i] += num;
             }
         }
         if (n > 1) { primes[n]++; }
     }
     LL res = 1;
     for (auto& p : primes) { res = res * (p.second + 1) % mod; }
     cout << res << endl;
     return 0;
 }
