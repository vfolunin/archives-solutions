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
    reverse(a.begin(), a.end());

    vector<vector<int>> cost(h, vector<int>(w, -1e9));
    cost[0][0] = a[0][0];
    vector<vector<pair<pair<int, int>, char>>> from(h, vector<pair<pair<int, int>, char>>(w));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y && cost[y][x] < cost[y - 1][x] + a[y][x]) {
                cost[y][x] = cost[y - 1][x] + a[y][x];
                from[y][x] = { { y - 1, x }, 'N' };
            }
            if (x && cost[y][x] < cost[y][x - 1] + a[y][x]) {
                cost[y][x] = cost[y][x - 1] + a[y][x];
                from[y][x] = { { y, x - 1 }, 'E' };
            }
        }
    }

    string path;
    for (int y = h - 1, x = w - 1; y || x; ) {
        auto &[py, px] = from[y][x].first;
        path += from[y][x].second;
        y = py;
        x = px;
    }
    reverse(path.begin(), path.end());

    cout << cost[h - 1][w - 1] << "\n" << path;
}