class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, int distLimit, vector<int> &cost) {
        vector<int> dist(graph.size(), 1e9);
        dist[0] = 0;
        set<vector<int>> q = { { cost[0], dist[0], 0 } };

        while (!q.empty()) {
            int totalCost = q.begin()->at(0), d = q.begin()->at(1), v = q.begin()->at(2);
            q.erase(q.begin());
            
            if (d > distLimit)
                continue;
            
            if (v == graph.size() - 1)
                return totalCost;

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > d + w) {
                    dist[to] = d + w;
                    q.insert({ totalCost + cost[to], dist[to], to });
                }
            }
        }

        return -1;
    }

public:
    int minCost(int distLimit, vector<vector<int>> &edges, vector<int> &cost) {
        vector<vector<pair<int, int>>> graph(cost.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }
        
        return dijkstra(graph, distLimit, cost);
    }
};