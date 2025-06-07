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

    int res = 0;
    for (int y = 1; y < h; y++) {
        for (int x = 1; x < w; x++) {
            if (a[y][x]) {
                a[y][x] = 1 + min({ a[y - 1][x - 1], a[y - 1][x], a[y][x - 1] });
                res = max(res, a[y][x]);
            }
        }
    }

    cout << res;
}