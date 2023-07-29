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

    int daysInMonth(int m) {
        static vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[m];
    }

    Date &operator++(int) {
        day++;
        if (day > daysInMonth(month)) {
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
        char dot;
        return in >> date.day >> dot >> date.month >> dot >> date.year;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Date a, b;
    cin >> a >> b;

    int res = 0;
    while (a != b) {
        a++;
        res++;
    }

    cout << res;
}