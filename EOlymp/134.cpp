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

    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int res = 0;
    for (int y = -200; y <= 200; y++) {
        for (int x = -200; x <= 200; x++) {
            int dy1 = y1 - y, dx1 = x1 - x;
            int dy2 = y2 - y, dx2 = x2 - x;
            res += dy1 * dy1 + dx1 * dx1 <= r1 * r1 || dy2 * dy2 + dx2 * dx2 <= r2 * r2;
        }
    }

    cout << res;
}