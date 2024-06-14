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

    for (int y = 0; y < h; y++) {
        int maxValue = 0;
        for (int x = 0; x < w; x++) {
            res += maxValue < a[y][x];
            maxValue = max(maxValue, a[y][x]);
        }

        maxValue = 0;
        for (int x = w - 1; x >= 0; x--) {
            res += maxValue < a[y][x];
            maxValue = max(maxValue, a[y][x]);
        }
    }

    for (int x = 0; x < w; x++) {
        int maxValue = 0;
        for (int y = 0; y < h; y++) {
            res += maxValue < a[y][x];
            maxValue = max(maxValue, a[y][x]);
        }

        maxValue = 0;
        for (int y = h - 1; y >= 0; y--) {
            res += maxValue < a[y][x];
            maxValue = max(maxValue, a[y][x]);
        }
    }

    cout << res;
}