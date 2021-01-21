#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 410;

int n ;

int res[7];

unordered_map<int, int> mapper;

bool is_leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

void init_mapper() {
    mapper[4] = 30;
    mapper[6] = 30;
    mapper[9] = 30;
    mapper[11] = 30;
    mapper[2] = 28;
    mapper[1] = 31;
    mapper[3] = 31;
    mapper[5] = 31;
    mapper[7] = 31;
    mapper[8] = 31;
    mapper[10] = 31;
    mapper[12] = 31;
}

int get_ans(int start_day, int year) {
    bool flag = is_leap(year);
    for (int i = 1;i<=12;i++) {
        res[(start_day + 5) % 7]++;
        int remain;
        if (i == 2 && flag) {
            remain = (mapper[i] + 1) % 7;
        } else {
            remain = mapper[i] % 7;
        }
        start_day = (start_day + remain) % 7;
    }
    return start_day;
}

int main() {
    init_mapper();
    cin >> n;
    int start_day = 1;
    for (int i = 0;i<n;i++) {
        start_day = get_ans(start_day, 1900 + i);
    }
    cout << res[6] << ' ' << res[0] << ' ';
    for (int i = 1;i<=5;i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
