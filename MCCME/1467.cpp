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
    vector<int> days = { 0, 31, 28 + isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d, m, y;
    cin >> d >> m >> y;

    for (int i = 0; i < 2; i++) {
        d++;
        if (d > daysInMonth(m, y)) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
    }

    cout << d << " " << m << " " << y;
}