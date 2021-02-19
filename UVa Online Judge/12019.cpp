#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetMonth, targetDay;
    cin >> targetMonth >> targetDay;

    static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int month = 1, day = 1, weekDay = 5;
    while (month != targetMonth || day != targetDay) {
        if (++day > days[month]) {
            day = 1;
            month++;
        }
        weekDay = (weekDay + 1) % 7;
    }

    static string name[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    cout << name[weekDay] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}