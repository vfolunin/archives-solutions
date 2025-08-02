class Solution {
    bool dijkstra(vector<vector<pair<int, int>>> &graph, int weightThreshold, long long distLimit) {
        vector<long long> dist(graph.size(), 1e18);
        dist[0] = 0;
        set<pair<long long, int>> q = { { dist[0], 0 } };

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == graph.size() - 1)
                return 1;

            for (auto &[to, weight] : graph[v]) {
                if (weight >= weightThreshold && dist[to] > dist[v] + weight && dist[v] + weight <= distLimit) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + weight;
                    q.insert({ dist[to], to });
                }
            }
        }

        return 0;
    }

public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long distLimit) {
        vector<vector<pair<int, int>>> graph(online.size());
        for (vector<int> &edge : edges)
            if (online[edge[0]] && online[edge[1]])
                graph[edge[0]].push_back({ edge[1], edge[2] });

        int l = -1, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (dijkstra(graph, m, distLimit))
                l = m;
            else
                r = m;
        }
        return l;
    }
};