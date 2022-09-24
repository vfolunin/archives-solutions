class Solution {
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        dist[start] = 0;
        set<pair<int, int>> q = { { dist[start], start } };

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
    int reachableNodes(vector<vector<int>> &edges, int limit, int vertexCount) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] + 1 });
            graph[edge[1]].push_back({ edge[0], edge[2] + 1 });
        }
        
        vector<int> dist = dijkstra(graph, 0);
        
        int res = 0;
        for (int d : dist)
            res += d <= limit;
        
        for (vector<int> &edge : edges) {
            int l = max(0, limit - dist[edge[0]]);
            int r = max(0, limit - dist[edge[1]]);
            res += min(edge[2], l + r);
        }
        
        return res;
    }
};