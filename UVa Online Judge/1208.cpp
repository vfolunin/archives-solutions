#include <iostream>
#include <algorithm>
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
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        if (w != that.w)
            return w < that.w;
        if (a != that.a)
            return a < that.a;
        return b < that.b;
    }
};

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int w;
            cin >> w;
            if (b + 1 < vertexCount)
                cin.ignore();

            if (a < b && w)
                edges.push_back({ a, b, w });
        }
    }

    sort(edges.begin(), edges.end());

    cout << "Case " << test << ":\n";
    DSU dsu(vertexCount);
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            cout << (char)('A' + a) << "-" << (char)('A' + b) << " " << w << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}