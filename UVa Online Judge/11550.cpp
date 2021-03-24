#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<pair<int, int>> edges(edgeCount, { -1, -1 });
    bool fail = 0;

    for (int v = 0; v < vertexCount; v++) {
        for (int e = 0; e < edgeCount; e++) {
            int x;
            cin >> x;
            if (x) {
                if (edges[e].first == -1)
                    edges[e].first = v;
                else if (edges[e].second == -1)
                    edges[e].second = v;
                else
                    fail = 1;
            }
        }
    }

    for (auto &[a, b] : edges)
        fail |= a == -1 || b == -1;

    sort(edges.begin(), edges.end());
    for (int i = 1; i < edgeCount; i++)
        fail |= edges[i - 1] == edges[i];

    cout << (!fail ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}