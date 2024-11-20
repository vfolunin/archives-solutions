#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int rectangleCount;
    cin >> rectangleCount;

    vector<vector<int>> rectangles(rectangleCount, vector<int>(4));
    for (vector<int> &r : rectangles) {
        cin >> r[0] >> r[1] >> r[2] >> r[3];
        if (r[0] > r[2])
            swap(r[0], r[2]);
        if (r[1] > r[3])
            swap(r[1], r[3]);
    }

    long long res = 0;
    for (int mask = 1; mask < (1 << rectangles.size()); mask++) {
        int ones = 0, xl = -1e9, yl = -1e9, xr = 1e9, yr = 1e9;

        for (int bit = 0; bit < rectangles.size(); bit++) {
            if (mask & (1 << bit)) {
                ones++;
                xl = max(xl, rectangles[bit][0]);
                yl = max(yl, rectangles[bit][1]);
                xr = min(xr, rectangles[bit][2]);
                yr = min(yr, rectangles[bit][3]);
            }
        }

        long long dx = max(0, xr - xl);
        long long dy = max(0, yr - yl);
        res += (ones % 2 ? 1 : -1) * dx * dy;
    }

    cout << res;
}