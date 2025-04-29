#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT2D {
    vector<vector<long long>> f;

    BIT2D(int h, int w) : f(h, vector<long long>(w)) {}

    long long sum(int yr, int xr) {
        long long res = 0;
        for (int y = yr; y >= 0; y = (y & (y + 1)) - 1)
            for (int x = xr; x >= 0; x = (x & (x + 1)) - 1)
                res += f[y][x];
        return res;
    }

    long long sum(int yl, int xl, int yr, int xr) {
        long long res = sum(yr, xr);
        if (yl)
            res -= sum(yl - 1, xr);
        if (xl)
            res -= sum(yr, xl - 1);
        if (yl && xl)
            res += sum(yl - 1, xl - 1);
        return res;
    }

    void add(int yCell, int xCell, int delta) {
        for (int y = yCell; y < f.size(); y |= y + 1)
            for (int x = xCell; x < f[0].size(); x |= x + 1)
                f[y][x] += delta;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    BIT2D bit2d(h, w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            bit2d.add(y, x, value);
        }
    }

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int y, x, value;
            cin >> y >> x >> value;

            bit2d.add(y - 1, x - 1, value);
        } else {
            int yl, xl, yr, xr;
            cin >> yl >> xl >> yr >> xr;
            if (yl > yr)
                swap(yl, yr);
            if (xl > xr)
                swap(xl, xr);

            cout << bit2d.sum(yl - 1, xl - 1, yr - 1, xr - 1) << "\n";
        }
    }
}