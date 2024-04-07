#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x) {
    a[y][x] = '#';
    int res = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#')
            res += dfs(a, ty, tx);
    }

    return res;
}

bool solve() {
    int w, h;
    cin >> w >> h;
    if (!w)
        return 0;

    vector<string> a(h);
    int startY, startX;

    for (int y = 0; y < h; y++) {
        cin >> a[y];
        if (int x = a[y].find('@'); x != -1) {
            startY = y;
            startX = x;
        }
    }

    cout << dfs(a, startY, startX) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}