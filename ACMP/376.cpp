#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, year;

    bool operator != (const Date &that) const {
        return day != that.day || month != that.month || year != that.year;
    }

    bool isLeap(int year) {
        return year % 400 == 0 || year % 100 && year % 4 == 0;
    }

    int daysInMonth(int month, int year) {
        vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
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
        return *this;
    }

    friend istream &operator >> (istream &in, Date &date) {
        return in >> date.day >> date.month >> date.year;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int day, month;
    Date date;
    cin >> day >> month >> date;

    int res = 0;
    while (date.day != day || date.month != month) {
        date++;
        res++;
    }

    cout << res;
}