#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 100 && year % 4 == 0;
}

void solve() {
    int year, month, day;
    cin >> year >> month >> day;

    vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int res = day;
    for (int m = 1; m < month; m++)
        res += days[m];

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}