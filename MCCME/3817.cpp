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

    int h, w, y1, x1, h1, w1, h2, w2;
    cin >> w >> h >> x1 >> y1 >> w1 >> h1 >> w2 >> h2;
    y1 = h - h1 - y1 + 1;
    x1--;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = y1; y < y1 + h1; y++)
        for (int x = x1; x < x1 + w1; x++)
            a[y][x] = 1;

    int res = 0;
    for (int y = 0; y + h2 <= h; y++) {
        for (int x = 0; x + w2 <= w; x++) {
            bool ok = 1;
            for (int dy = 0; ok && dy < h2; dy++)
                for (int dx = 0; ok && dx < w2; dx++)
                    ok &= !a[y + dy][x + dx];
            res += ok;
        }
    }

    cout << res;
}