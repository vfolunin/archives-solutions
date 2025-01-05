#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<vector<int>> &p, int y1, int x1, int y2, int x2) {
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

    int h, w, windowH, windowW;
    cin >> h >> w >> windowH >> windowW;

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

    int res = 0;
    for (int y = 0; y + windowH <= h; y++)
        for (int x = 0; x + windowW <= w; x++)
            res = max(res, sum(p, y, x, y + windowH - 1, x + windowW - 1));

    cout << res << "\n";
}