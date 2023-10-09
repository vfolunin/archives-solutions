class Solution {
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        set<pair<int, int>> q;

        dist[start] = 0;
        q.insert({ dist[start], start });

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
    int minimumDistance(int vertexCount, vector<vector<int>> &edges, int start, vector<int> &marked) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });
        
        vector<int> dist = dijkstra(graph, start);

        int res = 1e9;
        for (int v : marked)
            res = min(res, dist[v]);
        return res != 1e9 ? res : -1;
    }
};