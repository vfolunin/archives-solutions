struct Edge {
    int to, l, r;
};

class Solution {
    int dijkstra(vector<vector<Edge>> &graph) {
        vector<int> dist(graph.size(), 2e9);
        set<pair<int, int>> q;

        dist[0] = 0;
        q.insert({ 0, 0 });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == graph.size() - 1)
                return dist[v];

            for (auto &[to, l, r] : graph[v]) {
                if (dist[v] <= r && dist[to] > max(dist[v], l) + 1) {
                    q.erase({ dist[to], to });
                    dist[to] = max(dist[v], l) + 1;
                    q.insert({ dist[to], to });
                }
            }
        }

        return -1;
    }

public:
    int minTime(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<Edge>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2], edge[3] });
        
        return dijkstra(graph);
    }
};