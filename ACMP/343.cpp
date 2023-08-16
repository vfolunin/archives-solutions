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

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    vector<vector<int>> a(h, vector<int>(w));
    int res = 0;

    for (int i = 0; i < queryCount; i++) {
        int type, y, x;
        cin >> type >> y >> x;
        type--;
        y--;
        x--;

        int holeY = y + type / 2;
        int holeX = x + type % 2;

        bool ok = 1;
        for (int ty = y; ty < y + 2; ty++)
            for (int tx = x; tx < x + 2; tx++)
                ok &= 0 <= ty && ty < h && 0 <= tx && tx < w && (ty == holeY && tx == holeX || !a[ty][tx]);

        if (ok) {
            for (int ty = y; ty < y + 2; ty++)
                for (int tx = x; tx < x + 2; tx++)
                    if (ty != holeY || tx != holeX)
                        a[ty][tx] = 1;
            res += 3;
        }
    }

    cout << res;
}