#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, year;

    bool isLeap(int year) {
        return year % 400 == 0 || year % 100 && year % 4 == 0;
    }

    int daysInMonth(int month, int year) {
        vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
    }

    bool operator < (const Date &that) const {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    int toTime() {
        int time = 0;
        for (int y = 2013; y < year; y++)
            time += (365 + isLeap(y)) * 24 * 60;
        for (int m = 1; m < month; m++)
            time += daysInMonth(m, year) * 24 * 60;
        for (int d = 1; d < day; d++)
            time += 24 * 60;
        return time;
    }

    friend istream &operator >> (istream &in, Date &date) {
        char dash;
        return in >> date.year >> dash >> date.month >> dash >> date.day;
    }
};

int readTime() {
    Date date;
    cin >> date;

    int time = date.toTime();

    int hours, minutes;
    char colon;
    cin >> hours >> colon >> minutes;

    time += hours * 60 + minutes;
    return time;
}

void solve() {
    int segmentCount, extraTime;
    cin >> segmentCount >> extraTime;

    vector<pair<int, int>> events;
    for (int i = 0; i < segmentCount; i++) {
        string s;
        cin >> s;

        events.push_back({ readTime(), 1 });
        events.push_back({ readTime() + extraTime, -1 });
    }

    sort(events.begin(), events.end());

    int cur = 0, res = 0;
    for (auto &[_, delta] : events) {
        cur += delta;
        res = max(res, cur);
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