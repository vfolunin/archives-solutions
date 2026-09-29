class Solution {
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<long long> dist(graph.size(), 1e18);
        set<pair<long long, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, weight] : graph[v]) {
                if (dist[to] > dist[v] + weight) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return dist;
    }

public:
    long long minCostExcludingMax(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<long long> distA = dijkstra(graph, 0);
        vector<long long> distB = dijkstra(graph, graph.size() - 1);

        long long res = 1e18;
        for (vector<int> &edge : edges) {
            res = min(res, distA[edge[0]] + distB[edge[1]]);
            res = min(res, distA[edge[1]] + distB[edge[0]]);
        }
        return res;
    }
};