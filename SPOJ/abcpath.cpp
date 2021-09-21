#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<string> &a, int y, int x, vector<vector<int>> &memo) {
    int &res = memo[y][x];
    if (res != -1)
        return res;

    res = 1;

    static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[y][x] + 1 == a[ty][tx])
            res = max(res, 1 + rec(a, ty, tx, memo));
    }

    return res;
}

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> memo(h, vector<int>(w, -1));
    int res = 0;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == 'A')
                res = max(res, rec(a, y, x, memo));

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}