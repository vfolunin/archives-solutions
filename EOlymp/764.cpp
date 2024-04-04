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

    int h, w, rectangleH, rectangleW, cellCount;
    cin >> h >> w >> rectangleH >> rectangleW >> cellCount;

    vector<vector<int>> p(h, vector<int>(w));
    for (int i = 0; i < cellCount; i++) {
        int y, x;
        cin >> y >> x;
        p[y - 1][x - 1] = 1;
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
    for (int yl = 0, yr = rectangleH - 1; yr < h; yl++, yr++)
        for (int xl = 0, xr = rectangleW - 1; xr < w; xl++, xr++)
            res += !getSum(p, yl, xl, yr, xr);

    cout << res;
}