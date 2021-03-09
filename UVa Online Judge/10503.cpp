#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int last, int target, int dist, vector<pair<int, int>> &edges, vector<int> &used) {
    if (!dist)
        return last == target;
    for (int i = 0; i < edges.size(); i++) {
        if (used[i])
            continue;
        if (edges[i].first == last) {
            used[i] = 1;
            if (rec(edges[i].second, target, dist - 1, edges, used))
                return 1;
            used[i] = 0;
        }
        if (edges[i].second == last) {
            used[i] = 1;
            if (rec(edges[i].first, target, dist - 1, edges, used))
                return 1;
            used[i] = 0;
        }
    }
    return 0;
}

bool solve() {
    int dist, edgeCount;
    if (!(cin >> dist >> edgeCount))
        return 0;

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges)
        cin >> a >> b;

    vector<int> used(edgeCount);
    bool can = rec(b1, a2, dist, edges, used);

    cout << (can ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}