#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

unordered_set<int> getDists(vector<vector<pair<int, int>>> &graph) {
    vector<unordered_set<int>> dists(graph.size());
    dists[0].insert(0);

    for (int v = 0; v < graph.size(); v++)
        for (int dist : dists[v])
            for (auto &[to, weight] : graph[v])
                dists[to].insert(dist + weight);

    return dists.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<pair<int, int>>> graph1(vertexCount);
    vector<vector<pair<int, int>>> graph2(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight1, weight2;
        cin >> a >> b >> weight1 >> weight2;
        a--;
        b--;

        graph1[a].push_back({ b, weight1 });
        graph2[a].push_back({ b, weight2 });
    }

    unordered_set<int> dists1 = getDists(graph1);
    unordered_set<int> dists2 = getDists(graph2);

    int res = 2e9;
    for (int dist : dists1)
        if (dists2.count(dist))
            res = min(res, dist);

    if (res != 2e9)
        cout << res;
    else
        cout << "IMPOSSIBLE";
}