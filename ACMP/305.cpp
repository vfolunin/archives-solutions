#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<vector<int>> &p, int yl, int xl, int yr, int xr) {
    int res = p[yr][xr];
    if (yl)
        res -= p[yl - 1][xr];
    if (xl)
        res -= p[yr][xl - 1];
    if (yl && xl)
        res += p[yl - 1][xl - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, shipCount;
    cin >> h >> w >> shipCount;

    vector<vector<int>> p(h, vector<int>(w));
    for (int i = 0; i < shipCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        y1 = max(y1 - 2, 0);
        x1 = max(x1 - 2, 0);
        y2 = min(y2, h - 1);
        x2 = min(x2, w - 1);

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                p[y][x] = 1;
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    int res = 0;
    for (int y1 = 0; y1 < h; y1++)
        for (int x1 = 0; x1 < w; x1++)
            for (int y2 = y1; y2 < h; y2++)
                for (int x2 = x1; x2 < w; x2++)
                    if (!getSum(p, y1, x1, y2, x2))
                        res = max(res, (y2 - y1 + 1) * (x2 - x1 + 1));

    cout << res;
}