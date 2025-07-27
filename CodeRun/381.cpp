#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dayCount;
    string firstDayName;
    cin >> dayCount >> firstDayName;

    vector<string> dayNames = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int firstDayIndex = find(dayNames.begin(), dayNames.end(), firstDayName) - dayNames.begin();

    for (int day = -firstDayIndex + 1; day <= dayCount; day++) {
        if (day >= 1)
            cout << setw(2) << setfill('.') << day;
        else
            cout << "..";
        if (day + 1 <= dayCount)
            cout << ((day + firstDayIndex) % 7 ? " " : "\n");
    }
}