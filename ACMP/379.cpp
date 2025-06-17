#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int daysInMonth(int m) {
    vector<int> days = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

int rec(int d, int m) {
    if (m > 12 || d > daysInMonth(m))
        return 1;

    static vector<vector<int>> memo(32, vector<int>(13, -1));
    int &res = memo[d][m];
    if (res != -1)
        return res;

    if (d == 31 && m == 12 ||
        rec(d + 1, m) == 2 || rec(d + 2, m) == 2 ||
        rec(d, m + 1) == 2 || rec(d, m + 2) == 2)
        return res = 1;

    return res = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d, m;
    cin >> d >> m;

    cout << rec(d, m);
}