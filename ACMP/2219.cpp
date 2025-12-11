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

    int limit, step, factor;
    cin >> limit >> step >> factor;

    vector<string> a(3000, string(3000, '.'));
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int y = 1500, x = 1500, d = 1, yl = y, xl = x, yr = y, xr = x;
    a[y][x] = '#';

    for (int i = 0; i < limit; ) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; i < limit && k < step; i++, k++) {
                y += dy[d];
                x += dx[d];
                a[y][x] = '#';
                yl = min(yl, y);
                xl = min(xl, x);
                yr = max(yr, y);
                xr = max(xr, x);
            }
            d = (d + 1) % dy.size();
        }
        step *= factor;
    }

    cout << (yr - yl + 1) << " " << (xr - xl + 1) << "\n";
    for (int y = yl; y <= yr; y++) {
        for (int x = xl; x <= xr; x++)
            cout << a[y][x];
        cout << "\n";
    }
}