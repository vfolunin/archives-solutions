#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher2D {
    vector<unsigned long long> py, px;
    vector<vector<unsigned long long>> h;

    Hasher2D(const vector<string> &a, unsigned long long factorY = 29, unsigned long long factorX = 31) {
        py.push_back(1);
        for (int y = 1; y < a.size(); y++)
            py.push_back(py[y - 1] * factorY);

        px.push_back(1);
        for (int x = 1; x < a[0].size(); x++)
            px.push_back(px[x - 1] * factorX);

        h.assign(a.size(), vector<unsigned long long>(a[0].size()));
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                h[y][x] = a[y][x] - 'a' + 1;
                if (y)
                    h[y][x] += h[y - 1][x] * factorY;
                if (x)
                    h[y][x] += h[y][x - 1] * factorX;
                if (y && x)
                    h[y][x] -= h[y - 1][x - 1] * factorY * factorX;
            }
        }
    }

    inline unsigned long long getHash(int yl, int xl, int yr, int xr) {
        unsigned long long res = h[yr][xr];
        if (yl)
            res -= py[yr - yl + 1] * h[yl - 1][xr];
        if (xl)
            res -= px[xr - xl + 1] * h[yr][xl - 1];
        if (yl && xl)
            res += py[yr - yl + 1] * px[xr - xl + 1] * h[yl - 1][xl - 1];
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<string> b(h, string(w, ' '));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            b[y][x] = a[h - 1 - y][w - 1 - x];

    Hasher2D ha(a), hb(b);
    int res = 0;
    for (int yl = 0; yl < h; yl++)
        for (int xl = 0; xl < w; xl++)
            for (int yr = yl; yr < h; yr++)
                for (int xr = xl; xr < w; xr++)
                    res += ha.getHash(yl, xl, yr, xr) == hb.getHash(h - 1 - yr, w - 1 - xr, h - 1 - yl, w - 1 - xl);

    cout << res;
}