#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100;
}

int daysInMonth(int m, int y) {
    if (m == 2)
        return isLeap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    return 31;
}

struct Date {
    int d, m, y;

    Date() {}

    Date(int d, int m, int y) : d(d), m(m), y(y) {}

    bool operator < (const Date &that) const {
        if (y != that.y)
            return y < that.y;
        if (m != that.m)
            return m < that.m;
        return d < that.d;
    }

    bool canUseNextDay() const {
        return *this < Date(4, 11, 2001);
    }

    Date nextDay() const {
        Date res(d + 1, m, y);
        if (res.d > daysInMonth(res.m, res.y)) {
            res.d = 1;
            res.m++;
            if (res.m > 12) {
                res.m = 1;
                res.y++;
            }
        }
        return res;
    }

    bool canUseNextMonth() const {
        int nm = m + 1, ny = y;
        if (nm > 12) {
            nm = 1;
            ny++;
        }
        if (d > daysInMonth(nm, ny))
            return 0;
        return Date(d, nm, ny) < Date(4, 11, 2001);
    }

    Date nextMonth() const {
        int nm = m + 1, ny = y;
        if (nm > 12) {
            nm = 1;
            ny++;
        }
        return Date(d, nm, ny);
    }
};

int rec(const Date &date) {
    static map<Date, int> memo;
    if (memo.count(date))
        return memo[date];

    if (date.canUseNextMonth() && rec(date.nextMonth()) == 2)
        return memo[date] = 1;
    if (date.canUseNextDay() && rec(date.nextDay()) == 2)
        return memo[date] = 1;

    return memo[date] = 2;
}

void solve() {
    Date date;
    cin >> date.y >> date.m >> date.d;

    cout << (rec(date) == 1 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}