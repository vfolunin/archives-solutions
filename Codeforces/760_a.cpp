#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int month, day;
    cin >> month >> day;

    vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = daysInMonth[month - 1];

    int weeks = 0;
    if (day != 1) {
        weeks++;
        days -= 8 - day;
    }
    weeks += (days + 6) / 7;

    cout << weeks;
}