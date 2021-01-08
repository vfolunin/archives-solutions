#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
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
        if (rand() & 1)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

void solve(int test) {
    int n;
    cin >> n;
    cin.ignore();

    DSU dsu(n);
    int res[2] = {};

    while (1) {
        char type = cin.get();
        if (cin.eof() || type == '\n')
            break;
        
        int a, b;
        cin >> a >> b;
        cin.ignore();

        if (type == 'c')
            dsu.merge(a - 1, b - 1);
        else
            res[dsu.connected(a - 1, b - 1)]++;
    }

    if (test)
        cout << "\n";
    cout << res[1] << "," << res[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}