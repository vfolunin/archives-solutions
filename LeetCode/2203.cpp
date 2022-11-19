class Solution {
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<long long> dist(graph.size(), 1e15);
        dist[start] = 0;
        set<pair<long long, int>> q = { { dist[start], start } };

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
    long long minimumWeight(int vertexCount, vector<vector<int>> &edges, int a, int b, int c) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        vector<vector<pair<int, int>>> graphR(vertexCount);
        
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graphR[edge[1]].push_back({ edge[0], edge[2] });
        }
        
        vector<long long> distA = dijkstra(graph, a);
        vector<long long> distB = dijkstra(graph, b);
        vector<long long> distC = dijkstra(graphR, c);
        
        long long res = 1e15;
        for (int v = 0; v < vertexCount; v++)
            res = min(res, distA[v] + distB[v] + distC[v]);
        return res != 1e15 ? res : -1;
    }
};