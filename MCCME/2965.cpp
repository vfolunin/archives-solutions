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

    vector<vector<int>> res = a;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                res[y][x] = max(res[y][x], res[y - 1][x] + a[y][x]);
            if (x)
                res[y][x] = max(res[y][x], res[y][x - 1] + a[y][x]);
        }
    }

    cout << res[h - 1][w - 1];
}