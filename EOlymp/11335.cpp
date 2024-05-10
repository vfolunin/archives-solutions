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

    int rectangleCount;
    cin >> rectangleCount;

    vector<vector<int>> deltas(h, vector<int>(w + 1));
    for (int i = 0; i < rectangleCount; i++) {
        int y1, y2, x1, x2;
        cin >> y1 >> y2 >> x1 >> x2;

        for (int y = y1 - 1; y < y2; y++) {
            deltas[y][x1 - 1]++;
            deltas[y][x2]--;
        }
    }

    long long res = 0;
    for (int y = 0; y < h; y++) {
        int segmentCount = 0;
        for (int x = 0; x < w; x++) {
            segmentCount += deltas[y][x];
            if (segmentCount)
                res += a[y][x];
        }
    }

    cout << res;
}