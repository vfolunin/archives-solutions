#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int day, year;
    string monthName;
    cin >> day >> monthName >> monthName >> year;

    static vector<string> monthNames = {
        "pop", "no", "zip", "zotz", "tzec",
        "xul", "yoxkin", "mol", "chen", "yax",
        "zac", "ceh", "mac", "kankin", "muan",
        "pax", "koyab", "cumhu", "uayet"
    };
    day += 20 * (find(monthNames.begin(), monthNames.end(), monthName) - monthNames.begin());
    day += 365 * year;

    static vector<string> dayNames = {
        "imix", "ik", "akbal", "kan", "chicchan",
        "cimi", "manik", "lamat", "muluk", "ok",
        "chuen", "eb", "ben", "ix", "mem",
        "cib", "caban", "eznab", "canac", "ahau"
    };

    cout << day % 13 + 1 << " " << dayNames[day % 20] << " " << day / 260 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cout << n << "\n";

    for (int i = 0; i < n; i++)
        solve();
}