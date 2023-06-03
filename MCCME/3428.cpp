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

    int res = -1e9;
    for (int y1 = 0; y1 < h; y1++) {
        for (int y2 = y1 + 1; y2 < h; y2++) {
            vector<int> sums;
            for (int x = 0; x < w; x++)
                sums.push_back(a[y1][x] + a[y2][x]);
            
            nth_element(sums.begin(), sums.end() - 2, sums.end());
            res = max(res, sums[sums.size() - 2] + sums[sums.size() - 1]);
        }
    }

    cout << res;
}