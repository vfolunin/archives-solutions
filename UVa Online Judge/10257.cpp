#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int sp, py, sy, j;
    if (!(cin >> sp >> py >> sy >> j))
        return 0;

    for (int y = 0; y <= j + 12; y++) {
        for (int p = y; y + p <= j + 12; p++) {
            int s = j + 12 - y - p;
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