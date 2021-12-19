#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<long long, long long> dfs(vector<vector<pair<int, long long>>> &graph, int v, int p,
                               vector<int> &tax, int capacity) {
    long long totalDist = 0, totalTax = tax[v];
    for (auto &[to, w] : graph[v]) {
        if (to == p)
            continue;
        auto [tDist, tTax] = dfs(graph, to, v, tax, capacity);
        totalDist += tDist;
        totalDist += w * ((tTax + capacity - 1) / capacity);
        totalTax += tTax;
    }
    return { totalDist, totalTax };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, capacity;
    cin >> vertexCount >> capacity;

    vector<int> tax(vertexCount);
    for (auto &t : tax)
        cin >> t;

    vector<vector<pair<int, long long>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    cout << dfs(graph, 0, -1, tax, capacity).first * 2 << "\n";
}