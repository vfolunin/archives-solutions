#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, blockCount;
    cin >> size >> blockCount;

    vector<vector<int>> p(size, vector<int>(size));
    for (int i = 0; i < blockCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int y = y1 - 1; y < y2; y++)
            for (int x = x1 - 1; x < x2; x++)
                p[y][x] = 1;
    }

    for (int y = 1; y < size; y++)
        for (int x = 0; x < size; x++)
            p[y][x] += p[y - 1][x];

    int res = 0;
    for (int y1 = 0; y1 < size; y1++) {
        for (int y2 = y1; y2 < size; y2++) {
            int cur = 0;
            for (int x = 0; x < size; x++) {
                if (p[y2][x] - (y1 ? p[y1 - 1][x] : 0))
                    cur = 0;
                else
                    cur++;
                res = max(res, cur * (y2 - y1 + 1));
            }
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}