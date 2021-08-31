#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT2D {
    vector<vector<int>> f;

    BIT2D(int h, int w) : f(h, vector<int>(w)) {}

    int query(int yr, int xr) {
        int res = 0;
        for (int y = yr; y >= 0; y = (y & (y + 1)) - 1)
            for (int x = xr; x >= 0; x = (x & (x + 1)) - 1)
                res += f[y][x];
        return res;
    }

    void modify(int yr, int xr, int val) {
        for (int y = yr; y < f.size(); y |= y + 1)
            for (int x = xr; x < f[0].size(); x |= x + 1)
                f[y][x] += val;
    }
};

struct BIT2DRangeSumRangeAdd {
    BIT2D t, ty, tx, tyx;

    BIT2DRangeSumRangeAdd(int h, int w) :
        t(h, w), ty(h, w), tx(h, w), tyx(h, w) {}

    int sum(int yr, int xr) {
        int res = tyx.query(yr, xr) * yr * xr;
        res += ty.query(yr, xr) * yr;
        res += tx.query(yr, xr) * xr;
        res += t.query(yr, xr);
        return res;
    }

    int sum(int yl, int xl, int yr, int xr) {
        int res = sum(yr, xr);
        if (yl)
            res -= sum(yl - 1, xr);
        if (xl)
            res -= sum(yr, xl - 1);
        if (yl && xl)
            res += sum(yl - 1, xl - 1);
        return res;
    }

    void add(int yl, int xl, int yr, int xr, int val) {
        tyx.modify(yl, xl, val);
        tyx.modify(yr + 1, xl, -val);
        tyx.modify(yl, xr + 1, -val);
        tyx.modify(yr + 1, xr + 1, val);

        ty.modify(yl, xl, val * (-xl + 1));
        ty.modify(yr + 1, xl, -val * (-xl + 1));
        ty.modify(yl, xr + 1, val * xr);
        ty.modify(yr + 1, xr + 1, -val * xr);

        tx.modify(yl, xl, val * (-yl + 1));
        tx.modify(yr + 1, xl, val * yr);
        tx.modify(yl, xr + 1, -val * (-yl + 1));
        tx.modify(yr + 1, xr + 1, -val * yr);

        t.modify(yl, xl, val * (-xl + 1) * (-yl + 1));
        t.modify(yr + 1, xl, val * (-xl + 1) * yr);
        t.modify(yl, xr + 1, val * xr * (-yl + 1));
        t.modify(yr + 1, xr + 1, val * xr * yr);
    }
};

void solve(int test) {
    int rectCount;
    cin >> rectCount;

    BIT2DRangeSumRangeAdd t(200, 200);

    for (int i = 0; i < rectCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += 100;
        y1 += 100;
        x2 += 99;
        y2 += 99;

        if (!t.sum(y1, x1, y2, x2))
            t.add(y1, x1, y2, x2, 1);
    }

    cout << "Case " << test << ": " << t.sum(0, 0, 199, 199) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}