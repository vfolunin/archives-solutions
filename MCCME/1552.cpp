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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
        a--;
        b--;
    }

    int res = vertexCount;
    for (int mask = 0; mask < (1 << vertexCount); mask++) {
        int ok = 1;
        for (auto &[a, b] : edges)
            ok &= (mask & (1 << a)) || (mask & (1 << b));
        if (ok)
            res = min(res, ones(mask));
    }

    cout << res;
}