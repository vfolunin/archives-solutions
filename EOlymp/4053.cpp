#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> res(h, vector<int>(w, -1));
    res[0][0] = a[0][0];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y >= 1 && x >= 2 && res[y - 1][x - 2] != -1)
                res[y][x] = max(res[y][x], res[y - 1][x - 2] + a[y][x]);
            if (y >= 2 && x >= 1 && res[y - 2][x - 1] != -1)
                res[y][x] = max(res[y][x], res[y - 2][x - 1] + a[y][x]);
        }
    }

    cout << res.back().back();
}