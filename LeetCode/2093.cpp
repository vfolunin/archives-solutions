class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, int discounts) {
        vector<vector<int>> dist(graph.size(), vector<int>(discounts + 1, 1e9));
        set<pair<int, pair<int, int>>> q;

        dist[0][0] = 0;
        q.insert({ dist[0][0], { 0, 0 } });

        while (!q.empty()) {
            auto [v, d] = q.begin()->second;
            q.erase(q.begin());

            if (v + 1 == graph.size())
                return dist[v][d];

            for (auto &[to, weight] : graph[v]) {
                if (dist[to][d] > dist[v][d] + weight) {
                    q.erase({ dist[to][d], { to, d } });
                    dist[to][d] = dist[v][d] + weight;
                    q.insert({ dist[to][d], { to, d } });
                }
                if (d < discounts && dist[to][d + 1] > dist[v][d] + weight / 2) {
                    q.erase({ dist[to][d + 1], { to, d + 1 } });
                    dist[to][d + 1] = dist[v][d] + weight / 2;
                    q.insert({ dist[to][d + 1], { to, d + 1 } });
                }
            }
        }

        return -1;
    }

public:
    int minimumCost(int vertexCount, vector<vector<int>> &edges, int discounts) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        return dijkstra(graph, discounts);
    }
};