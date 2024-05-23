#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, year;

    bool operator < (const Date &that) const {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    friend istream &operator >> (istream &in, Date &date) {
        char dot;
        return in >> date.day >> dot >> date.month >> dot >> date.year;
    }

    friend ostream &operator << (ostream &out, Date &date) {
        return out << date.day << "." << date.month << "." << date.year;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dateCount;
    cin >> dateCount;

    vector<Date> dates(dateCount);
    for (Date &date : dates)
        cin >> date;

    sort(dates.begin(), dates.end());

    for (Date &date : dates)
        cout << date << "\n";
}