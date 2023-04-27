#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int h, int w, int y, int x, vector<vector<int>> &memo) {
    const int MOD = 1e6 + 7;

    int &res = memo[y][x];
    if (res != -1)
        return res;

    if (!y && !x)
        return res = 1;

    static vector<int> dy = { -2, -2, -1, 1 };
    static vector<int> dx = { -1, 1, -2, -2 };

    res = 0;

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < h && 0 <= tx && tx < w)
            res = (res + rec(h, w, ty, tx, memo)) % MOD;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> memo(h, vector<int>(w, -1));
    cout << rec(h, w, h - 1, w - 1, memo);
}