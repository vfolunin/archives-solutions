#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, year, dayOfWeek;

    Date() {}

    Date(int dayNumber) {
        year = 1;
        while (dayNumber > daysInYear(year)) {
            dayNumber -= daysInYear(year);
            year++;
        }
        month = 1;
        while (dayNumber > daysInMonth(month, year)) {
            dayNumber -= daysInMonth(month, year);
            month++;
        }
        day = dayNumber;
    }

    bool isLeap(int year) {
        return year % 400 == 0 || year % 100 && year % 4 == 0;
    }

    int daysInYear(int year) {
        return isLeap(year) ? 366 : 365;
    }

    int daysInMonth(int month, int year) {
        vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
    }

    int dayNumber() {
        int res = 0;
        for (int i = 1; i < year; i++)
            res += daysInYear(i);
        for (int i = 1; i < month; i++)
            res += daysInMonth(i, year);
        res += day;
        return res;
    }

    Date &operator++(int) {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        dayOfWeek = (dayOfWeek + 1) % 7;
        return *this;
    }

    friend istream &operator >> (istream &in, Date &date) {
        char dot;
        return in >> date.day >> dot >> date.month >> dot >> date.year;
    }

    friend ostream &operator << (ostream &out, const Date &date) {
        out << setw(2) << setfill('0') << date.day << ".";
        out << setw(2) << setfill('0') << date.month << '.';
        out << setw(4) << setfill('0') << date.year;
        return out;
    }
};

bool can(vector<pair<int, int>> segments, int day) {
    multiset<int> deadlines;

    for (int i = 0; i < segments.size() || !deadlines.empty(); day++) {
        while (i < segments.size() && segments[i].first <= day) {
            deadlines.insert(segments[i].second);
            i++;
        }

        if (!deadlines.empty()) {
            if (*deadlines.begin() < day)
                return 0;
            deadlines.erase(deadlines.begin());
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int examCount;
    cin >> examCount;

    vector<pair<int, int>> segments;

    for (int i = 0; i < examCount; i++) {
        string name;
        Date date;
        int dayCount;
        cin >> name >> date >> dayCount;

        int dayNumber = date.dayNumber();

        segments.push_back({ dayNumber - dayCount, dayNumber - 1 });
        segments.push_back({ dayNumber, dayNumber });
    }

    sort(segments.begin(), segments.end());

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(segments, m))
            l = m;
        else
            r = m;
    }

    if (l)
        cout << Date(l);
    else
        cout << "Impossible";
}