#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x) {
    a[y][x] = '#';

    static int dy[] = { -1, 0 , 1, 0 };
    static int dx[] = { 0 , 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#')
            dfs(a, ty, tx);
    }
}

bool solve(int test) {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '-') {
                res++;
                dfs(a, y, x);
            }
        }
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}