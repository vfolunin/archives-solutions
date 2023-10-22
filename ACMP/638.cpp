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

    int daysInMonth, targetRow, daysInWeek, badDaysInWeek, firstWeekDay;
    cin >> daysInMonth >> targetRow >> daysInWeek >> badDaysInWeek >> firstWeekDay;

    vector<int> isBad(daysInMonth);

    for (int i = 0; i < badDaysInWeek; i++) {
        int weekDay;
        cin >> weekDay;

        for (int day = (weekDay - firstWeekDay + daysInWeek) % daysInWeek; day < daysInMonth; day += daysInWeek)
            isBad[day] = 1;
    }

    int badDaysInMonth;
    cin >> badDaysInMonth;

    for (int i = 0; i < badDaysInMonth; i++) {
        int day;
        cin >> day;

        isBad[day - 1] = 1;
    }

    int row = 0, res = 0;
    for (int i = 0; i < daysInMonth; i++) {
        if (isBad[i])
            row = 0;
        else
            row++;
        res += row >= targetRow;
    }

    cout << res;
}