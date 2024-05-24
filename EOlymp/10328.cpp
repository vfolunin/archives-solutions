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
        for (int x = w - 1; x >= 0; x--)
            cin >> a[y][x];

    vector<vector<int>> cost(h, vector<int>(w));
    cost[0][0] = a[0][0];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                cost[y][x] = max(cost[y][x], cost[y - 1][x] + a[y][x]);
            if (x)
                cost[y][x] = max(cost[y][x], cost[y][x - 1] + a[y][x]);
        }
    }

    cout << cost[h - 1][w - 1];
}