#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, edgeCount, pathCount;
    cin >> vertexCount >> edgeCount >> pathCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a - 1].push_back({ b - 1, weight });
    }

    vector<priority_queue<long long>> dist(graph.size());
    dist[0].push(0);
    multiset<pair<long long, int>> q = { { 0, 0 } };

    while (!q.empty()) {
        auto [distV, v] = *q.begin();
        q.erase(q.begin());

        for (auto &[to, weight] : graph[v]) {
            if (dist[to].size() < pathCount || dist[to].top() > distV + weight) {
                if (dist[to].size() == pathCount) {
                    q.erase(q.find({ dist[to].top(), to }));
                    dist[to].pop();
                }
                dist[to].push(distV + weight);
                q.insert({ distV + weight, to });
            }
        }
    }

    vector<long long> res;
    while (!dist.back().empty()) {
        res.push_back(dist.back().top());
        dist.back().pop();
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
}