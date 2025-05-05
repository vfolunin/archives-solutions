#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges)
        cin >> a >> b;

    int res = 0;
    for (int mask = 0; mask < (1 << vertexCount); mask++) {
        if (res > ones(mask))
            continue;

        bool ok = 1;
        for (auto &[a, b] : edges) {
            if (mask & (1 << (a - 1))) {
                if (b > 0)
                    ok &= !!(mask & (1 << (b - 1)));
                else
                    ok &= !(mask & (1 << (-b - 1)));
                if (!ok)
                    break;
            }
        }

        if (ok)
            res = max(res, ones(mask));
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}