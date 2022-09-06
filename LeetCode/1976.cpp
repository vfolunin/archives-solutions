class Solution {
    const long long MOD = 1e9 + 7;
    
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<long long> dist(graph.size(), 1e18);
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
    
    long long rec(vector<vector<pair<int, int>>> &graph, vector<long long> &distA, vector<long long> &distB,
                  int v, vector<long long> &ways) {
        if (ways[v])
            return ways[v];
        
        for (auto &[to, weight] : graph[v])
            if (distA[v] + weight + distB[to] == distA.back())
                ways[v] = (ways[v] + rec(graph, distA, distB, to, ways)) % MOD;
        
        return ways[v];
    }
    
public:
    int countPaths(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }
        
        vector<long long> distA = dijkstra(graph, 0);
        vector<long long> distB = dijkstra(graph, graph.size() - 1);
        
        vector<long long> ways(graph.size());
        ways.back() = 1;
        
        return rec(graph, distA, distB, 0, ways);
    }
};