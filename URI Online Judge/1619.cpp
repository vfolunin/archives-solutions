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

    bool operator < (const Date &that) const {
        if (y != that.y)
            return y < that.y;
        if (m != that.m)
            return m < that.m;
        return d < that.d;
    }

    Date &operator ++(int) {
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
    char c;
    in >> d.y >> c >> d.m >> c >> d.d;
    return in;
}

void solve() {
    Date a, b;
    cin >> a >> b;

    if (b < a)
        swap(a, b);

    int res = 0;
    while (a < b) {
        a++;
        res++;
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