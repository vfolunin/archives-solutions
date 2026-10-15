#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int d, m, y;

    static bool isLeap(int y) {
        return y % 400 == 0 || y % 4 == 0 && y % 100;
    }

    static int daysInMonth(int m, int y) {
        static vector<int> d = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return d[m] + (m == 2 && isLeap(y));
    }

    bool operator == (const Date &that) const {
        return d == that.d && m == that.m && y == that.y;
    }

    Date &operator ++() {
        d++;
        if (d > daysInMonth(m, y)) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        return *this;
    }
};

istream &operator >> (istream &in, Date &d) {
    in >> d.d >> d.m >> d.y;
    return in;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int resDays = 0, resKw = 0;

    Date d1, d2;
    int kw1, kw2;
    cin >> d2 >> kw2;

    for (int i = 1; i < n; i++) {
        d1 = d2;
        kw1 = kw2;
        cin >> d2 >> kw2;
        if (i && ++d1 == d2) {
            resDays++;
            resKw += kw2 - kw1;
        }
    }

    cout << resDays << " " << resKw << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}