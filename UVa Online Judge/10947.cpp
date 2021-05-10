#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
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
    }
};

bool solve() {
    int time, velocity;
    if (!(cin >> time >> velocity))
        return 0;

    double limit = time * velocity;

    vector<double> x(2), y(2), r(2);
    cin >> x[0] >> y[0] >> r[0];
    cin >> x[1] >> y[1] >> r[1];

    int vertexCount;
    cin >> vertexCount;
    
    x.resize(vertexCount + 2);
    y.resize(vertexCount + 2);
    r.resize(vertexCount + 2);
    for (int i = 2; i < x.size(); i++)
        cin >> x[i] >> y[i] >> r[i];

    DSU dsu(x.size());
    for (int i = 0; i < x.size(); i++)
        for (int j = i + 1; j < x.size(); j++)
            if (hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j] <= limit + 1e-9)
                dsu.merge(i, j);

    if (dsu.connected(0, 1))
        cout << "Larry and Ryan will escape!\n";
    else
        cout << "Larry and Ryan will be eaten to death.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}