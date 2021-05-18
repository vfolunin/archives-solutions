#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SegmentTree2D {
    vector<vector<pair<int, int>>> t;
    int size;

    void buildX(int vy, int vx, int vxl, int vxr, vector<int> &a) {
        if (vxl == vxr) {
            t[vy][vx] = { a[vxl], a[vxr] };
            return;
        }
        int vxm = vxl + (vxr - vxl) / 2;
        buildX(vy, 2 * vx + 1, vxl, vxm, a);
        buildX(vy, 2 * vx + 2, vxm + 1, vxr, a);
        auto [lMin, lMax] = t[vy][2 * vx + 1];
        auto [rMin, rMax] = t[vy][2 * vx + 2];
        t[vy][vx] = { min(lMin, rMin), max(lMax, rMax) };
    }

    void buildY(int vy, int vyl, int vyr, vector<vector<int>> &a) {
        if (vyl == vyr) {
            buildX(vy, 0, 0, size - 1, a[vyl]);
            return;
        }
        int vym = vyl + (vyr - vyl) / 2;
        buildY(2 * vy + 1, vyl, vym, a);
        buildY(2 * vy + 2, vym + 1, vyr, a);
        for (int vx = 0; vx < 4 * size; vx++) {
            auto [lMin, lMax] = t[2 * vy + 1][vx];
            auto [rMin, rMax] = t[2 * vy + 2][vx];
            t[vy][vx] = { min(lMin, rMin), max(lMax, rMax) };
        }
    }

    pair<int, int> queryX(int vy, int vx, int vxl, int vxr, int xl, int xr) {
        if (xr < vxl || vxr < xl)
            return { 2e9, -2e9 };
        if (xl <= vxl && vxr <= xr)
            return t[vy][vx];
        int vxm = vxl + (vxr - vxl) / 2;
        auto [lMin, lMax] = queryX(vy, 2 * vx + 1, vxl, vxm, xl, xr);
        auto [rMin, rMax] = queryX(vy, 2 * vx + 2, vxm + 1, vxr, xl, xr);
        return { min(lMin, rMin), max(lMax, rMax) };
    }

    pair<int, int> queryY(int vy, int vyl, int vyr, int yl, int yr, int xl, int xr) {
        if (yr < vyl || vyr < yl)
            return { 2e9, -2e9 };
        if (yl <= vyl && vyr <= yr)
            return queryX(vy, 0, 0, size - 1, xl, xr);
        int vym = vyl + (vyr - vyl) / 2;
        auto [lMin, lMax] = queryY(2 * vy + 1, vyl, vym, yl, yr, xl, xr);
        auto [rMin, rMax] = queryY(2 * vy + 2, vym + 1, vyr, yl, yr, xl, xr);
        return { min(lMin, rMin), max(lMax, rMax) };
    }

    void modifyX(int vy, int vx, int vxl, int vxr, int x, int val) {
        if (x < vxl || vxr < x)
            return;
        if (x == vxl && vxl == vxr) {
            t[vy][vx] = { val, val };
            return;
        }
        int vxm = vxl + (vxr - vxl) / 2;
        modifyX(vy, 2 * vx + 1, vxl, vxm, x, val);
        modifyX(vy, 2 * vx + 2, vxm + 1, vxr, x, val);
        auto [lMin, lMax] = t[vy][2 * vx + 1];
        auto [rMin, rMax] = t[vy][2 * vx + 2];
        t[vy][vx] = { min(lMin, rMin), max(lMax, rMax) };
    }

    void modifyY(int vy, int vyl, int vyr, int y, int x, int val) {
        if (y < vyl || vyr < y)
            return;
        if (y == vyl && vyl == vyr) {
            modifyX(vy, 0, 0, size - 1, x, val);
            return;
        }
        int vym = vyl + (vyr - vyl) / 2;
        modifyY(2 * vy + 1, vyl, vym, y, x, val);
        modifyY(2 * vy + 2, vym + 1, vyr, y, x, val);
        for (int vx = 0; vx < 4 * size; vx++) {
            auto [lMin, lMax] = t[2 * vy + 1][vx];
            auto [rMin, rMax] = t[2 * vy + 2][vx];
            t[vy][vx] = { min(lMin, rMin), max(lMax, rMax) };
        }
    }

public:
    SegmentTree2D(vector<vector<int>> &a) : size(a.size()) {
        t.assign(size * 4, vector<pair<int, int>>(size * 4));
        buildY(0, 0, size - 1, a);
    }

    pair<int, int> query(int yl, int yr, int xl, int xr) {
        return queryY(0, 0, size - 1, yl, yr, xl, xr);
    }

    void modify(int y, int x, int val) {
        modifyY(0, 0, size - 1, y, x, val);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    SegmentTree2D segmentTree(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 'q') {
            int xl, yl, xr, yr;
            cin >> yl >> xl >> yr >> xr;
            auto [resMin, resMax] = segmentTree.query(yl - 1, yr - 1, xl - 1, xr - 1);
            cout << resMax << " " << resMin << "\n";
        } else {
            int x, y, v;
            cin >> y >> x >> v;
            segmentTree.modify(y - 1, x - 1, v);
        }
    }
}