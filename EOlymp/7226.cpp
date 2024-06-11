#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day = 1, month = 1;

    int daysInMonth(int month) {
        static vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
    }

    Date &operator++(int) {
        day++;
        if (day > daysInMonth(month)) {
            day = 1;
            month++;
        }
        return *this;
    }

    friend ostream &operator << (ostream &out, Date &date) {
        return out << date.day << " " << date.month;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    n--;

    Date date;
    for (int i = 0; i < n; i++)
        date++;

    cout << date;
}