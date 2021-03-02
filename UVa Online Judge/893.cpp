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

bool solve() {
    int n, d, m, y;
    cin >> n >> d >> m >> y;

    if (!d && !m && !y && !n)
        return 0;

    y += 400 * (n / 146097);
    n %= 146097;

    vector<int> daysInMonth = { 0, 31, 28 + isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (n--) {
        d++;
        if (d > daysInMonth[m]) {
            d = 1;
            m++;
            if (m == 13) {
                m = 1;
                y++;
                daysInMonth[2] = 28 + isLeap(y);
            }
        }
    }
    
    cout << d << " " << m << " " << y << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}