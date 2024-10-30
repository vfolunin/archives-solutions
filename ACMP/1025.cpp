#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> minSum(h, vector<int>(w, 1e9));
    minSum[0][0] = a[0][0];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                minSum[y][x] = min(minSum[y][x], minSum[y - 1][x] + a[y][x]);
            if (x)
                minSum[y][x] = min(minSum[y][x], minSum[y][x - 1] + a[y][x]);
        }
    }

    vector<vector<int>> maxSum(h, vector<int>(w, -1e9));
    maxSum[0][0] = a[0][0];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y)
                maxSum[y][x] = max(maxSum[y][x], maxSum[y - 1][x] + a[y][x]);
            if (x)
                maxSum[y][x] = max(maxSum[y][x], maxSum[y][x - 1] + a[y][x]);
        }
    }

    cout << (minSum[h - 1][w - 1] == maxSum[h - 1][w - 1] ? "Y" : "N");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}