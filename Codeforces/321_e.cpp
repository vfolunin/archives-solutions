#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct PrefixSum2D {
    vector<vector<int>> p;

    PrefixSum2D(vector<vector<int>> &a) {
        p = a;
        for (int y = 0; y < p.size(); y++) {
            for (int x = 0; x < p[0].size(); x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
    }

    int getSum(int yl, int xl, int yr, int xr) {
        int res = p[yr][xr];
        if (yl)
            res -= p[yl - 1][xr];
        if (xl)
            res -= p[yr][xl - 1];
        if (yl && xl)
            res += p[yl - 1][xl - 1];
        return res;
    }

    int getSum(int l, int r) {
        return getSum(l, l, r, r) / 2;
    }
};

void rec(int parts, int sizeL, int sizeR, int prevSizeL, int prevSizeR, PrefixSum2D &prefixSums, vector<vector<int>> &res) {
    if (sizeL > sizeR)
        return;

    int size = sizeL + (sizeR - sizeL) / 2;
    int bestPrevSize = prevSizeL;

    for (int prevSize = prevSizeL; prevSize <= prevSizeR && prevSize < size; prevSize++) {
        int candidate = res[parts - 1][prevSize] + prefixSums.getSum(prevSize, size - 1);
        if (res[parts][size] > candidate) {
            res[parts][size] = candidate;
            bestPrevSize = prevSize;
        }
    }

    rec(parts, sizeL, size - 1, prevSizeL, bestPrevSize, prefixSums, res);
    rec(parts, size + 1, sizeR, bestPrevSize, prevSizeR, prefixSums, res);
}

int readInt() {
    char c;
    while (1) {
        c = getchar();
        if (isdigit(c))
            break;
    }

    int res = c - '0';
    while (1) {
        c = getchar();
        if (!isdigit(c))
            break;
        res = res * 10 + c - '0';
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size = readInt();
    int partCount = readInt();

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            a[y][x] = readInt();

    PrefixSum2D prefixSums(a);

    vector<vector<int>> res(partCount + 1, vector<int>(a.size() + 1, 1e9));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++)
        rec(parts, 0, a.size(), 0, a.size(), prefixSums, res);

    cout << res[partCount][a.size()];
}