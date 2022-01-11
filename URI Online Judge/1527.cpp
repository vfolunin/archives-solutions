#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, sum;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        sum.resize(n);
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
        if (rand() % 2) {
            id[ri] = rj;
            sum[rj] += sum[ri];
        } else {
            id[rj] = ri;
            sum[ri] += sum[rj];
        }
    }
};

bool solve() {
    int playerCount, queryCount;
    cin >> playerCount >> queryCount;

    if (!playerCount)
        return 0;

    DSU dsu(playerCount);

    for (int i = 0; i < playerCount; i++)
        cin >> dsu.sum[i];

    int res = 0;

    for (int i = 0; i < queryCount; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        a--;
        b--;

        if (type == 1) {
            dsu.merge(a, b);
        } else {
            res += dsu.connected(0, a) && dsu.sum[dsu.find(a)] > dsu.sum[dsu.find(b)] ||
                   dsu.connected(0, b) && dsu.sum[dsu.find(b)] > dsu.sum[dsu.find(a)];
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}