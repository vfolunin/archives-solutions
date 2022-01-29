#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int mask, vector<int> &odd, vector<vector<int>> &dist,
    vector<int> &memoWeight, vector<pair<int, int>> &memoEdge) {
    if (memoWeight[mask] != -1)
        return;

    memoWeight[mask] = 1e9;

    int a = 0;
    while (!(mask & (1 << a)))
        a++;

    for (int b = a + 1; b < odd.size(); b++) {
        if (!(mask & (1 << b)))
            continue;

        int nextMask = mask ^ (1 << a) ^ (1 << b);
        rec(nextMask, odd, dist, memoWeight, memoEdge);

        if (memoWeight[mask] > dist[odd[a]][odd[b]] + memoWeight[nextMask]) {
            memoWeight[mask] = dist[odd[a]][odd[b]] + memoWeight[nextMask];
            memoEdge[mask] = { a, b };
        }
    }
}

int euler(map<int, multiset<pair<int, int>>> &graph, int v) {
    int res = 0;
    while (!graph[v].empty()) {
        auto [to, w] = *graph[v].begin();
        graph[v].erase(graph[v].find({ to, w }));
        graph[to].erase(graph[to].find({ v, w }));
        res += w + euler(graph, to);
    }
    return res;
}

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    map<int, multiset<pair<int, int>>> graph;
    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].insert({ b, w });
        graph[b].insert({ a, w });
        dist[a][b] = dist[b][a] = min(dist[a][b], w);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    vector<int> odd;
    for (int v = 0; v < vertexCount; v++)
        if (graph[v].size() % 2)
            odd.push_back(v);

    vector<int> memoWeight(1 << odd.size(), -1);
    memoWeight[0] = 0;
    vector<pair<int, int>> memoEdge(1 << odd.size());
    rec((1 << odd.size()) - 1, odd, dist, memoWeight, memoEdge);

    for (int mask = (1 << odd.size()) - 1; mask; ) {
        auto [oa, ob] = memoEdge[mask];
        int a = odd[oa], b = odd[ob], w = dist[a][b];

        graph[a].insert({ b, w });
        graph[b].insert({ a, w });

        mask ^= (1 << oa) ^ (1 << ob);
    }

    cout << euler(graph, 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}