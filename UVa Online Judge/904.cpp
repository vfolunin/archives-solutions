#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Box {
    int x1, y1, z1, x2, y2, z2;
};

bool solve() {
    int boxCount;
    if (!(cin >> boxCount))
        return 0;

    vector<Box> boxes(boxCount);
    for (auto &[x1, y1, z1, x2, y2, z2] : boxes)
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    long long res = 0;

    for (int mask = 1; mask < (1 << boxCount); mask++) {
        int xl = -1e9, yl = -1e9, zl = -1e9, xr = 1e9, yr = 1e9, zr = 1e9, ones = 0;
        for (int bit = 0; bit < boxCount; bit++) {
            if (mask & (1 << bit)) {
                xl = max(xl, boxes[bit].x1);
                yl = max(yl, boxes[bit].y1);
                zl = max(zl, boxes[bit].z1);
                xr = min(xr, boxes[bit].x2);
                yr = min(yr, boxes[bit].y2);
                zr = min(zr, boxes[bit].z2);
                ones++;
            }
        }

        long long volume = 1LL * max(0, xr - xl) * max(0, yr - yl) * max(0, zr - zl);
        if (ones % 2)
            res -= (ones - 1) * volume;
        else
            res += (ones - 1) * volume;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}