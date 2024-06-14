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

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!y && !x)
                continue;

            int add = -1e9;
            if (y)
                add = max(add, a[y - 1][x]);
            if (x)
                add = max(add, a[y][x - 1]);
            if (y && x)
                add = max(add, a[y - 1][x - 1]);
            a[y][x] += add;
        }
    }

    cout << (a[h - 1][w - 1] > 0 ? "winner\n" : "loser\n") << a[h - 1][w - 1];
}