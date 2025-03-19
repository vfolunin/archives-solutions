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

    int h, w, delta;
    cin >> h >> w >> delta;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int res = 0;
    for (int y = 0; y + 1 < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] * 2 < a[y + 1][x])
                res += delta;

    cout << res;
}