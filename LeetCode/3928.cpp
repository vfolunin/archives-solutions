class Solution {
    vector<long long> dijkstra(vector<vector<pair<int, long long>>> &graph, int start) {
        vector<long long> dist(graph.size(), 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

        dist[start] = 0;
        q.push({ dist[start], start });

        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            if (d != dist[v])
                continue;

            for (auto &[to, weight] : graph[v]) {
                if (dist[to] > dist[v] + weight) {
                    dist[to] = dist[v] + weight;
                    q.push({ dist[to], to });
                }
            }
        }

        return dist;
    }

public:
    vector<int> minCost(int vertexCount, vector<int> &price, vector<vector<int>> &edges) {
        vector<vector<pair<int, long long>>> graph1(vertexCount), graph2(vertexCount);
        for (vector<int> &edge : edges) {
            int a = edge[0], b = edge[1], weight = edge[2], factor = edge[3];

            graph1[a].push_back({ b, weight });
            graph1[b].push_back({ a, weight });
            
            graph2[a].push_back({ b, 1LL * weight * factor });
            graph2[b].push_back({ a, 1LL * weight * factor });
        }

        vector<int> res = price;
        for (int v = 0; v < vertexCount; v++) {
            vector<long long> dist1 = dijkstra(graph1, v);
            vector<long long> dist2 = dijkstra(graph2, v);
            for (int to = 0; to < vertexCount; to++)
                res[v] = min<long long>(res[v], dist1[to] + price[to] + dist2[to]);
        }
        return res;
    }
};