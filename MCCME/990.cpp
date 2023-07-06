#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, dayOfWeek;

    int daysInMonth(int m) {
        vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[m];
    }

    Date &operator++() {
        day++;
        if (day > daysInMonth(month)) {
            day = 1;
            month++;
            if (month > 12)
                month = 1;
        }
        dayOfWeek = (dayOfWeek + 1) % 7;
        return *this;
    }

    bool isFree() {
        return dayOfWeek >= 5 || day == 23 && month == 2 || day == 8 && month == 3;
    }
};

int solve(int dayOfWeek, int holidayCount) {
    Date date = { 1, 1, dayOfWeek };
    int row = 0, maxRow = 0;

    for (int i = 0; i < 365; i++) {
        if (date.isFree() || holidayCount) {
            holidayCount -= !date.isFree();
            row++;
        } else {
            row = 0;
        }
        maxRow = max(maxRow, row);
        ++date;
    }

    return maxRow;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int holidayCount;
    cin >> holidayCount;

    int res = 0;
    for (int dayOfWeek = 0; dayOfWeek < 7; dayOfWeek++)
        res = max(res, solve(dayOfWeek, holidayCount));

    cout << res;
}