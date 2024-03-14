#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, isSink;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        isSink.assign(n, 1);
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
            isSink[rj] &= isSink[ri];
        } else {
            id[rj] = ri;
            isSink[ri] &= isSink[rj];
        }
    }

    int sinkCount() {
        set<int> sinks;
        for (int v = 0; v < id.size(); v++) {
            int root = find(v);
            if (isSink[root])
                sinks.insert(root);
        }
        return sinks.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];
    
    DSU dsu(h * w);
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (ty < 0 || ty >= h || tx < 0 || tx >= w)
                    continue;

                if (a[y][x] == a[ty][tx])
                    dsu.merge(y * w + x, ty * w + tx);

                if (a[y][x] > a[ty][tx])
                    dsu.isSink[dsu.find(y * w + x)] = 0;
            }
        }
    }

    cout << dsu.sinkCount();
}