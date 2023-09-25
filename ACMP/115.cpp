#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSum(vector<vector<long long>> &p, int yl, int xl, int yr, int xr) {
    long long res = p[yr][xr];
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

    int h, w;
    cin >> h >> w;

    vector<vector<long long>> p(h, vector<long long>(w));
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

    long long res = -1e9;
    for (int yl = 0; yl < h; yl++)
        for (int xl = 0; xl < w; xl++)
            for (int yr = yl; yr < h; yr++)
                for (int xr = xl; xr < w; xr++)
                    res = max(res, getSum(p, yl, xl, yr, xr));

    cout << res;
}