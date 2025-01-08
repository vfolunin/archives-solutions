#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, dist;

    DSU(int n) {
        for (int v = 0; v < n; v++) {
            id.push_back(v);
            dist.push_back(0);
        }
    }

    int find(int i) {
        vector<int> stack = { i };
        while (id[i] != i) {
            stack.push_back(id[i]);
            i = id[i];
        }

        int r = stack.back(), d = 0;
        while (!stack.empty()) {
            int i = stack.back();
            stack.pop_back();
            id[i] = r;
            dist[i] += d;
            d = dist[i];
        }

        return d;
    }

    void merge(int i, int j) {
        id[i] = j;
        dist[i] = abs(i - j) % 1000;
    }
};

void solve() {
    int n;
    cin >> n;

    DSU dsu(n);

    while (1) {
        char op;
        cin >> op;

        if (op == 'E') {
            int i;
            cin >> i;

            cout << dsu.find(i - 1) << "\n";
        } else if (op == 'I') {
            int i, j;
            cin >> i >> j;

            dsu.merge(i - 1, j - 1);
        } else {
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}