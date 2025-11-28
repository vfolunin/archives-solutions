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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    vector<pair<int, int>> start(5);
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++)
            if (isdigit(a[y][x]))
                start[a[y][x] - '1'] = { y, x };
    }

    for (auto &[y, x] : start)
        cout << dfs(a, y, x) << "\n";
}