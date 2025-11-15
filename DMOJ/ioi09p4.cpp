#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<vector<int>> &p, int yl, int xl, int yr, int xr) {
    long long res = p[yr][xr];
    if (yl)
        res -= p[yl - 1][xr];
    if (xl)
        res -= p[yr][xl - 1];
    if (yl && xl)
        res += p[yl - 1][xl - 1];
    return res;
}

int rec(vector<vector<int>> &p, int yl, int xl, int yr, int xr) {
    static vector memo(51, vector(51, vector(51, vector<int>(51, -1))));
    int &res = memo[yl][xl][yr][xr];
    if (res != -1)
        return res;

    if (yl == yr && xl == xr)
        return res = 0;

    res = 1e9;
    for (int y = yl; y < yr; y++)
        res = min(res, rec(p, yl, xl, y, xr) + rec(p, y + 1, xl, yr, xr));
    for (int x = xl; x < xr; x++)
        res = min(res, rec(p, yl, xl, yr, x) + rec(p, yl, x + 1, yr, xr));
    res += getSum(p, yl, xl, yr, xr);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> p(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> p[y][x];
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    cout << rec(p, 0, 0, h - 1, w - 1);
}