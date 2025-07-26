#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> makeA(int h, int w, int mask) {
    vector<vector<int>> a(h + 2, vector<int>(w + 2));
    for (int y = 1; y <= h; y++)
        for (int x = 1; x <= w; x++, mask /= 2)
            a[y][x] = mask % 2;
    return a;
}

void dfs(vector<vector<int>> &a, int y, int x, int value) {
    a[y][x] = -1;

    static const vector<vector<int>> dy = { { -1, -1, -1, 0, 1, 1, 1, 0 }, { -1, 0, 1, 0 } };
    static const vector<vector<int>> dx = { { -1, 0, 1, 1, 1, 0, -1, -1 }, { 0, 1, 0, -1 } };

    for (int d = 0; d < dy[value].size(); d++) {
        int ty = y + dy[value][d];
        int tx = x + dx[value][d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == value)
            dfs(a, ty, tx, value);
    }
}

bool check(vector<vector<int>> a) {
    vector<int> seen(2);

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            if (a[y][x] == -1)
                continue;

            if (seen[a[y][x]])
                return 0;
            seen[a[y][x]] = 1;

            dfs(a, y, x, a[y][x]);
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    int res = 0;
    for (int mask = 0; mask < (1 << (h * w)); mask++)
        res += check(makeA(h, w, mask));

    cout << res - 1;
}