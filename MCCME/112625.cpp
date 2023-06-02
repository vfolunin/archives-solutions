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
    int maxSize = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            if (c == '1') {
                a[y][x] = 1;
                if (y && x)
                    a[y][x] = 1 + min({ a[y - 1][x - 1], a[y - 1][x], a[y][x - 1] });
            }

            maxSize = max(maxSize, a[y][x]);
        }
    }

    cout << maxSize;
}