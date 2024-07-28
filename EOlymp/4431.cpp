#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    int xl, yl, xr, yr;

    friend istream &operator >> (istream &in, Rectangle &r) {
        return in >> r.xl >> r.yl >> r.xr >> r.yr;
    }
};

struct Compressor {
    map<int, int> c;
    vector<int> d;

    void add(int x) {
        c[x];
    }

    void prepare() {
        for (auto &[coord, compressed] : c) {
            compressed = d.size();
            d.push_back(coord);
        }
    }

    int size() {
        return d.size();
    }

    int compress(int x) {
        return c[x];
    }

    int decompress(int x) {
        return d[x];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int rectangleCount;
    cin >> rectangleCount;

    vector<Rectangle> rectangles(rectangleCount);
    for (Rectangle &rectangle : rectangles)
        cin >> rectangle;

    Compressor cy, cx;
    for (auto &[xl, yl, xr, yr] : rectangles) {
        cy.add(yl);
        cy.add(yr);
        cx.add(xl);
        cx.add(xr);
    }
    cy.prepare();
    cx.prepare();

    vector<vector<int>> a(cy.size() + 1, vector<int>(cx.size() + 1));
    for (auto &[xl, yl, xr, yr] : rectangles) {
        int cyl = cy.compress(yl);
        int cyr = cy.compress(yr);
        int cxl = cx.compress(xl);
        int cxr = cx.compress(xr);

        a[cyl][cxl]++;
        a[cyl][cxr]--;
        a[cyr][cxl]--;
        a[cyr][cxr]++;
    }

    for (int y = 0; y <= cy.size(); y++) {
        for (int x = 0; x <= cx.size(); x++) {
            if (y)
                a[y][x] += a[y - 1][x];
            if (x)
                a[y][x] += a[y][x - 1];
            if (y && x)
                a[y][x] -= a[y - 1][x - 1];
        }
    }

    long long res = 0;
    for (int y = 0; y + 1 < cy.size(); y++)
        for (int x = 0; x + 1 < cx.size(); x++)
            if (a[y][x])
                res += 1LL * (cy.decompress(y + 1) - cy.decompress(y)) * (cx.decompress(x + 1) - cx.decompress(x));

    cout << res;
}