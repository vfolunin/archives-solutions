#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x) {
    a[y][x] = 'x';

    static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != 'M' && a[ty][tx] != 'x')
            dfs(a, ty, tx);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int startY, startX, finishY, finishX;
    for (int y = 0; y < h; y++) {
        cin >> a[y];

        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'G') {
                startY = y;
                startX = x;
            } else if (a[y][x] == 'E') {
                finishY = y;
                finishX = x;
            }
        }
    }

    dfs(a, startY, startX);

    cout << (a[finishY][finishX] == 'x' ? "YES" : "NO");
}