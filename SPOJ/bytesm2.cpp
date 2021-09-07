#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> stoneCount(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> stoneCount[y][x];
            if (y) {
                int pred = stoneCount[y - 1][x];
                if (x)
                    pred = max(pred, stoneCount[y - 1][x - 1]);
                if (x + 1 < w)
                    pred = max(pred, stoneCount[y - 1][x + 1]);
                stoneCount[y][x] += pred;
            }
        }
    }

    cout << *max_element(stoneCount[h - 1].begin(), stoneCount[h - 1].end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}