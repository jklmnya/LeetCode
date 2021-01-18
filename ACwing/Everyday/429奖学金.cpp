/**
 * 重载op
 **/ 
 
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;

int n;

struct student {
    int num;
    int total;
    int china;
    
    bool operator<(const student& s) const {
        if (total > s.total) {
            return true;
        } else if (total == s.total) {
            if (china > s.china) {
                return true;
            } else if (china == s.china) {
                if (num < s.num) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
} students[N];

int main() {
    cin >> n;
    int x, y, z;
    for (int i = 1;i<=n;i++) {
        cin >> x >> y >> z;
        students[i] = {i, x + y + z, x};
    }
    sort(students + 1, students + n + 1);
    for (int i = 1;i<=5;i++) {
        cout << students[i].num << ' ' << students[i].total << endl;
    }
    return 0;
}
