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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> b(h, vector<int>(w));
    vector<multiset<int>> deltas(w);
    long long res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> b[y][x];
            deltas[x].insert(a[y][x] - b[y][x]);
            res += b[y][x];
        }
    }

    for (multiset<int> &deltas : deltas) {
        if (*deltas.rbegin() <= 0) {
            res += *deltas.rbegin();
        } else {
            for (int delta : deltas)
                if (delta > 0)
                    res += delta;
        }
    }

    cout << res;
}