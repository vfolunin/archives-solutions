#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string monthName, dayName;
    cin >> monthName >> dayName;

    static vector<string> month = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
    };
    static vector<string> day = {
        "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
    };
    static vector<int> dayCount = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int m = find(month.begin(), month.end(), monthName) - month.begin();
    int d = find(day.begin(), day.end(), dayName) - day.begin();

    int res = 0;
    for (int i = 0; i < dayCount[m]; i++) {
        res += d >= 5;
        d = (d + 1) % 7;
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