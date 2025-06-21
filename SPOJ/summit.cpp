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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    vector<int> res;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool ok = 1;
            for (int d = 0; d < dy.size() && ok; d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                ok &= ty < 0 || ty >= h || tx < 0 || tx >= w || a[y][x] > a[ty][tx];
            }
            if (ok)
                res.push_back(a[y][x]);
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}