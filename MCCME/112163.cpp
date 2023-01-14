#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int daysInMonth(int m) {
    vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, d;
    cin >> m >> d;

    if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m)) {
        cout << -1;
        return 0;
    }

    int res = -d;
    for (int i = m; i <= 12; i++)
        res += daysInMonth(i);

    cout << res;
}