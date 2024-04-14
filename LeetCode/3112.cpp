class Solution {
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<int> &limit) {
        vector<int> dist(graph.size(), 1e9);
        set<pair<int, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > dist[v] + w && limit[to] > dist[v] + w) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + w;
                    q.insert({ dist[to], to });
                }
            }
        }

        for (int &d : dist)
            if (d == 1e9)
                d = -1;
        return dist;
    }

public:
    vector<int> minimumTime(int vertexCount, vector<vector<int>> &edges, vector<int> &limit) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        return dijkstra(graph, 0, limit);
    }
};