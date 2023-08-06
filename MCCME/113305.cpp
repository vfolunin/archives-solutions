#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x) {
    a[y][x] = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx])
            dfs(a, ty, tx);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, markedCount;
    cin >> h >> w >> markedCount;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < markedCount; i++) {
        int y, x;
        cin >> y >> x;
        a[y - 1][x - 1] = 1;
    }

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!a[y][x]) {
                dfs(a, y, x);
                res++;
            }
        }
    }

    cout << res;
}