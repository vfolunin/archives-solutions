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

    if (h < w)
        swap(h, w);

    vector<vector<int>> ways(h, vector<int>(1 << w));
    ways[0].assign(1 << w, 1);

    for (int y = 1; y < h; y++) {
        for (int mask = 0; mask < (1 << w); mask++) {
            for (int prevMask = 0; prevMask < (1 << w); prevMask++) {
                bool ok = 1;

                for (int i = 0; ok && i + 1 < w; i++) {
                    bool a = mask & (1 << i), b = mask & (1 << (i + 1));
                    bool c = prevMask & (1 << i), d = prevMask & (1 << (i + 1));
                    ok &= a != b || a != c || a != d || b != c || b != d || c != d;
                }

                if (ok)
                    ways[y][mask] += ways[y - 1][prevMask];
            }
        }
    }

    int res = 0;
    for (int mask = 0; mask < (1 << w); mask++)
        res += ways[h - 1][mask];

    cout << res;
}