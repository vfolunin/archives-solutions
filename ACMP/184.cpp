#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

struct DateTime {
    int month, day, hours, minutes;

    bool operator < (const DateTime &that) const {
        return tie(month, day, hours, minutes) < tie(that.month, that.day, that.hours, that.minutes);
    }

    bool operator <= (const DateTime &that) const {
        return tie(month, day, hours, minutes) <= tie(that.month, that.day, that.hours, that.minutes);
    }

    bool isWorkingTime() {
        return 10 <= hours && hours <= 17;
    }

    int daysInMonth(int month) {
        vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
    }

    DateTime &operator++(int) {
        minutes++;
        if (minutes > 59) {
            minutes = 0;
            hours++;
            if (hours > 23) {
                hours = 0;
                day++;
                if (day > daysInMonth(month)) {
                    day = 1;
                    month++;
                    if (month > 12)
                        month = 1;
                }
            }
        }
        return *this;
    }

    friend istream &operator >> (istream &in, DateTime &dateTime) {
        char c;
        return in >> dateTime.day >> c >> dateTime.month >> c >> dateTime.hours >> c >> dateTime.minutes;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dateTimeCount;
    cin >> dateTimeCount;

    vector<DateTime> dateTimes(dateTimeCount);
    for (DateTime &dateTime : dateTimes)
        cin >> dateTime;

    sort(dateTimes.begin(), dateTimes.end());

    int res = 0;
    for (int i = 0; i < dateTimes.size(); i += 2) {
        while (dateTimes[i] <= dateTimes[i + 1]) {
            res += dateTimes[i].isWorkingTime();
            dateTimes[i]++;
        }
    }

    cout << res / 60 << ":" << setw(2) << setfill('0') << res % 60;
}