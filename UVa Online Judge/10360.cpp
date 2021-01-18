#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int bombStrength, ratsCount;
    cin >> bombStrength >> ratsCount;
    
    vector<vector<int>> p(1025, vector<int>(1025));
    for (int i = 0; i < ratsCount; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        p[y][x] += k;
    }

    for (int y = 0; y < 1025; y++) {
        for (int x = 0; x < 1025; x++) {
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    int bestY = 0, bestX = 0, bestK = 0;
    for (int y = 0; y < 1025; y++) {
        for (int x = 0; x < 1025; x++) {
            int y1 = max(0, y - bombStrength), y2 = min(1024, y + bombStrength);
            int x1 = max(0, x - bombStrength), x2 = min(1024, x + bombStrength);
            int k = p[y2][x2];
            if (y1)
                k -= p[y1 - 1][x2];
            if (x1)
                k -= p[y2][x1 - 1];
            if (y1 && x1)
                k += p[y1 - 1][x1 - 1];
            if (k > bestK || k == bestK && make_pair(x, y) < make_pair(bestX, bestY)) {
                bestK = k;
                bestY = y;
                bestX = x;
            }
        }
    }

    cout << bestX << " " << bestY << " " << bestK << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}