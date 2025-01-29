#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

void rec(vector<pair<int, int>> &edges, int i, vector<vector<int>> &graph, vector<int> &cover, int curSize, int targetSize) {
    if (curSize > targetSize)
        return;

    if (i == edges.size()) {
        for (int v = 0; curSize < targetSize && v < graph.size(); v++) {
            if (!cover[v]) {
                cover[v]++;
                curSize++;
            }
        }

        cout << "Yes\n";
        for (int v = 0; v < graph.size(); v++)
            if (cover[v])
                cout << v + 1 << " ";
        exit(0);
    }

    auto &[a, b] = edges[i];
    if (cover[a] || cover[b]) {
        rec(edges, i + 1, graph, cover, curSize, targetSize);
        return;
    }

    for (int a : graph[b])
        curSize += !cover[a]++;
    rec(edges, i + 1, graph, cover, curSize, targetSize);
    for (int a : graph[b])
        curSize -= !--cover[a];

    if (graph[b].size() > 1) {
        curSize += !cover[b]++;
        rec(edges, i + 1, graph, cover, curSize, targetSize);
        curSize -= !--cover[b];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, targetCoverSize;
    cin >> vertexCount >> edgeCount >> targetCoverSize;

    vector<vector<int>> graph(vertexCount);
    vector<pair<int, int>> edges(edgeCount);

    for (auto &[a, b] : edges) {
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return graph[a.first].size() + graph[a.second].size() >
               graph[b.first].size() + graph[b.second].size();
    });

    vector<int> cover(vertexCount);
    rec(edges, 0, graph, cover, 0, targetCoverSize);

    cout << "No";
}