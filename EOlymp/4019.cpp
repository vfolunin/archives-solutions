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

    vector<vector<int>> cost(h, vector<int>(w, 1e9));
    cost[0][0] = a[0][0];
    vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, { -1, -1 }));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y && cost[y][x] > cost[y - 1][x] + a[y][x]) {
                cost[y][x] = cost[y - 1][x] + a[y][x];
                from[y][x] = { y - 1, x };
            }
            if (x && cost[y][x] > cost[y][x - 1] + a[y][x]) {
                cost[y][x] = cost[y][x - 1] + a[y][x];
                from[y][x] = { y, x - 1 };
            }
        }
    }

    vector<pair<int, int>> res;
    for (int y = h - 1, x = w - 1; y != -1; ) {
        res.push_back({ y, x });
        auto &[py, px] = from[y][x];
        y = py;
        x = px;
    }
    reverse(res.begin(), res.end());

    cout << cost[h - 1][w - 1] << "\n";
    for (auto &[y, x] : res)
        cout << y + 1 << " " << x + 1 << "\n";
}