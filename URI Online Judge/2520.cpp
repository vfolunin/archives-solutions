#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    int y1, x1, y2, x2;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int digit;
            cin >> digit;

            if (digit == 1) {
                y1 = y;
                x1 = x;
            }
            if (digit == 2) {
                y2 = y;
                x2 = x;
            }
        }
    }

    cout << abs(y1 - y2) + abs(x1 - x2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}