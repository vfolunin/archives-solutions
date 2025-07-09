#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

bool areMergeable(int a, int b, int limit) {
    int g = gcd(a, b);
    for (int d = 2; d * d <= g; d++) {
        if (g % d)
            continue;
        if (d >= limit)
            return 1;
        while (g % d == 0)
            g /= d;
    }
    return g >= limit;
}

void solve(int test) {
    int l, r, limit;
    cin >> l >> r >> limit;

    DSU dsu(r - l + 1);
    for (int a = l; a <= r; a++)
        for (int b = a + 1; b <= r; b++)
            if (areMergeable(a, b, limit))
                dsu.merge(a - l, b - l);

    cout << "Case #" << test << ": " << dsu.cc << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}