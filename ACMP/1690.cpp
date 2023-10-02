#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<vector<vector<int>>> &p, int zl, int yl, int xl, int zr, int yr, int xr) {
    int res = p[zr][yr][xr];
    if (zl)
        res -= p[zl - 1][yr][xr];
    if (yl)
        res -= p[zr][yl - 1][xr];
    if (xl)
        res -= p[zr][yr][xl - 1];
    if (zl && yl)
        res += p[zl - 1][yl - 1][xr];
    if (zl && xl)
        res += p[zl - 1][yr][xl - 1];
    if (yl && xl)
        res += p[zr][yl - 1][xl - 1];
    if (zl && yl && xl)
        res -= p[zl - 1][yl - 1][xl - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int zSize, ySize, xSize, queryCount;
    cin >> zSize >> ySize >> xSize >> queryCount;

    vector<vector<vector<int>>> p(zSize, vector<vector<int>>(ySize, vector<int>(xSize)));
    for (int z = 0; z < zSize; z++) {
        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                char c;
                cin >> c;

                p[z][y][x] = c - '0';
                if (z)
                    p[z][y][x] += p[z - 1][y][x];
                if (y)
                    p[z][y][x] += p[z][y - 1][x];
                if (x)
                    p[z][y][x] += p[z][y][x - 1];
                if (z && y)
                    p[z][y][x] -= p[z - 1][y - 1][x];
                if (z && x)
                    p[z][y][x] -= p[z - 1][y][x - 1];
                if (y && x)
                    p[z][y][x] -= p[z][y - 1][x - 1];
                if (z && y && x)
                    p[z][y][x] += p[z - 1][y - 1][x - 1];
            }
        }
    }

    for (int i = 0; i < queryCount; i++) {
        int zl, yl, xl, zr, yr, xr;
        cin >> zl >> yl >> xl >> zr >> yr >> xr;

        if (zl > zr)
            swap(zl, zr);
        if (yl > yr)
            swap(yl, yr);
        if (xl > xr)
            swap(xl, xr);

        cout << getSum(p, zl - 1, yl - 1, xl - 1, zr - 1, yr - 1, xr - 1) << "\n";
    }
}