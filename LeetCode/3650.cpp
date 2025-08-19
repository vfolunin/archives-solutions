class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph) {
        vector<int> dist(graph.size(), 1e9);
        set<pair<int, int>> q;

        dist[0] = 0;
        q.insert({ dist[0], 0 });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == graph.size() - 1)
                return dist[v];

            for (auto &[to, weight] : graph[v]) {
                if (dist[to] > dist[v] + weight) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return -1;
    }

public:
    int minCost(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] * 2 });
        }

        return dijkstra(graph);
    }
};