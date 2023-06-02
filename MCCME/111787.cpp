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
    int maxSize = 0, maxY, maxX;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x] && y && x)
                a[y][x] = 1 + min({ a[y - 1][x - 1], a[y - 1][x], a[y][x - 1] });

            if (maxSize < a[y][x]) {
                maxSize = a[y][x];
                maxY = y - a[y][x] + 1;
                maxX = x - a[y][x] + 1;
            }
        }
    }

    cout << maxSize << "\n" << maxY + 1 << " " << maxX + 1;
}