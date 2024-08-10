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
    int minValue = 1e9;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            minValue = min(minValue, a[y][x]);
        }
    }

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int used;
            cin >> used;
            res += !used && a[y][x] == minValue;
        }
    }

    cout << res;
}