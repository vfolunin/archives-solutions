#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<vector<int>> &p, int y1, int x1, int y2, int x2) {
    int res = p[y2][x2];
    if (y1)
        res -= p[y1 - 1][x2];
    if (x1)
        res -= p[y2][x1 - 1];
    if (y1 && x1)
        res += p[y1 - 1][x1 - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> p(size, vector<int>(size));
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> p[y][x];
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    int res = -1e9;
    for (int y1 = 0; y1 < size; y1++) {
        for (int y2 = y1; y2 < size; y2++) {
            int cur = -1e9;
            for (int x = 0; x < size; x++) {
                cur = max(cur + getSum(p, y1, x, y2, x), getSum(p, y1, x, y2, x));
                res = max(res, cur);
            }
        }
    }

    cout << res;
}