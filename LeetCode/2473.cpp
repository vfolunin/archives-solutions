class Solution {
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<long long> dist(graph.size(), 1e15);
        dist[start] = 0;
        set<pair<long long, int>> q = { { dist[start], start } };

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > dist[v] + w) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + w;
                    q.insert({ dist[to], to });
                }
            }
        }

        return dist;
    }

public:
    vector<long long> minCost(int vertexCount, vector<vector<int>> &edges, vector<int> &cost, int k) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back({ edge[1] - 1, edge[2] });
            graph[edge[1] - 1].push_back({ edge[0] - 1, edge[2] });
        }

        vector<long long> res(vertexCount, 1e18);
        for (int v = 0; v < vertexCount; v++) {
            vector<long long> dist = dijkstra(graph, v);
            for (int to = 0; to < vertexCount; to++)
                res[v] = min(res[v], dist[to] * (k + 1) + cost[to]);
        }
        return res;
    }
};