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

    Date &operator--() {
        if (!--day) {
            if (!--month) {
                year--;
                month = 12;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    friend istream &operator >> (istream &in, Date &date) {
        return in >> date.day >> date.month >> date.year;
    }

    friend ostream &operator << (ostream &out, Date &date) {
        return out << date.day << " " << date.month << " " << date.year;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Date date;
    cin >> date;

    cout << ----date;
}