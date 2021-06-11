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

    vector<set<int>> graph(vertexCount);
    set<pair<int, int>> edges;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b)
            swap(a, b);

        if (a != b) {
            graph[a].insert(b);
            edges.insert({ a, b });
        }
    }

    int res = 0;
    for (auto &[a, b] : edges)
        for (int c : graph[b])
            res += graph[a].count(c);
    
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}