#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long sp, py, sy, j;
    if (!(cin >> sp >> py >> sy >> j))
        return 0;

    long long middle = (j + 12 - sp - 2 * py) / 3;
    for (long long y = max(0LL, middle - 2); y <= middle + 2; y++) {
        for (long long p = max(y, y + py - 1); p <= y + py + 1 && y + p <= j + 12; p++) {
            long long s = j + 12 - y - p;
            if (s < p)
                continue;

            if (abs(s - p - sp) > 1)
                continue;
            if (abs(p - y - py) > 1)
                continue;
            if (abs(s - y - sy) > 1)
                continue;

            cout << s << " " << p << " " << y << "\n";
            return 1;
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}