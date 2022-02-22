#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int daysInYear, monthsInYear;
    cin >> daysInYear >> monthsInYear;

    vector<int> daysInMonth(monthsInYear);
    for (int &days : daysInMonth)
        cin >> days;

    int day = 1, month = 1, weekDay = 6, res = 0;
    while (month <= monthsInYear) {
        day++;
        if (day > daysInMonth[month - 1]) {
            day = 1;
            month++;
        }
        weekDay = (weekDay + 1) % 7;
        res += weekDay == 4 && day == 13;
    }

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