#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<vector<int>> u(h, vector<int>(w, 1)), ul = u, dl = u;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (x && a[y][x - 1] == a[y][x])
                ul[y][x] = ul[y][x - 1] + 1;

            if (y && a[y - 1][x] == a[y][x]) {
                u[y][x] = u[y - 1][x] + 1;
                ul[y][x] = min(ul[y - 1][x], ul[y][x]);
            }
        }
    }

    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            if (x && a[y][x - 1] == a[y][x])
                dl[y][x] = dl[y][x - 1] + 1;

            if (y < h - 1 && a[y][x] == a[y + 1][x])
                dl[y][x] = min(dl[y][x], dl[y + 1][x]);
        }
    }

    long long res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int curH = u[y][x];
            if (y >= curH && a[y - curH][x] != a[y][x] && u[y - curH][x] == curH &&
                y >= 2 * curH && a[y - 2 * curH][x] != a[y - curH][x] && u[y - 2 * curH][x] >= curH)
                res += min({ ul[y][x], ul[y - curH][x], dl[y - 3 * curH + 1][x] });
        }
    }

    cout << res;
}