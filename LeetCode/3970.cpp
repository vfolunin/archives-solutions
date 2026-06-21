class Solution {
    int dijkstra(vector<vector<pair<int, int>>> &graph, string &s, int limit) {
        vector<vector<int>> dist(graph.size(), vector<int>(limit, 1e9));
        set<pair<int, pair<int, int>>> q;

        dist[0][0] = 0;
        q.insert({ dist[0][0], { 0, 0 } });

        while (!q.empty()) {
            auto [v, count] = q.begin()->second;
            q.erase(q.begin());

            if (v == graph.size() - 1)
                return dist[v][count];

            for (auto &[to, weight] : graph[v]) {
                int toCount = s[v] == s[to] ? count + 1 : 0;
                if (toCount == limit)
                    continue;
                
                if (dist[to][toCount] > dist[v][count] + weight) {
                    q.erase({ dist[to][toCount], { to, toCount } });
                    dist[to][toCount] = dist[v][count] + weight;
                    q.insert({ dist[to][toCount], { to, toCount } });
                }
            }
        }

        return -1;
    }

public:
    int shortestPath(int vertexCount, vector<vector<int>> &edges, string &s, int limit) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });
        return dijkstra(graph, s, limit);
    }
};