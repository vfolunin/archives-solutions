#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, bx;
    cin >> h >> w >> bx;

    if (!h && !w)
        return 0;

    bx--;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    for (int by = 0; by < h; by++) {
        if (a[by][bx]) {
            cout << "BOOM " << by + 1 << " " << bx + 1 << "\n";
            return 1;
        }

        int l = bx - 1;
        while (!a[by][l])
            l--;

        int r = bx + 1;
        while (!a[by][r])
            r++;

        bx += a[by][l] - a[by][r];
        bx = max(bx, l);
        bx = min(bx, r);

        if (a[by][bx]) {
            cout << "BOOM " << by + 1 << " " << bx + 1 << "\n";
            return 1;
        }
    }

    cout << "OUT " << bx + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}