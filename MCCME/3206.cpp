#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, weight;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        weight.assign(n, 0);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j, int w) {
        int ri = find(i), rj = find(j);
        if (ri == rj) {
            weight[ri] += w;
            return;
        }
        if (rand() % 2) {
            id[ri] = rj;
            weight[rj] += weight[ri] + w;
        } else {
            id[rj] = ri;
            weight[ri] += weight[rj] + w;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, y, x, color;
    cin >> h >> w >> y >> x >> color;

    if (h % 2 && w % 2) {
        if (((y + x) % 2) ^ color)
            cout << "white";
        else
            cout << "black";
    } else {
        cout << "equal";
    }
}