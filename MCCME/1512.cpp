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
    vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, { -1, -1 }));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (!y && !x)
                continue;

            if (!x || y && a[y - 1][x] <= a[y][x - 1]) {
                a[y][x] += a[y - 1][x];
                from[y][x] = { y - 1, x };
            } else {
                a[y][x] += a[y][x - 1];
                from[y][x] = { y, x - 1 };
            }
        }
    }

    vector<pair<int, int>> path;
    for (int y = h - 1, x = w - 1; y != -1; ) {
        path.push_back({ y, x });
        auto &[py, px] = from[y][x];
        y = py;
        x = px;
    }
    reverse(path.begin(), path.end());

    cout << a[h - 1][w - 1] << "\n" << path.size() << "\n";
    for (auto &[y, x] : path)
        cout << y + 1 << " " << x + 1 << "\n";
}