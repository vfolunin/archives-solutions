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
        dayOfWeek = (dayOfWeek + 1) % 7;
        return *this;
    }

    friend ostream &operator << (ostream &out, Date &date) {
        static vector<string> names = {
            "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
        };
        out << names[date.dayOfWeek] << ", ";
        out << setw(2) << setfill('0') << date.day << ".";
        out << setw(2) << setfill('0') << date.month;
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    Date date = { 1, 1, 2008, 1 };
    for (int i = 0; i < n; i++)
        date++;

    cout << date;
}