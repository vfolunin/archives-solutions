class Solution {
    const long long MOD = 1e9 + 7;
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
        vector<int> dist(graph.size(), 2e9);
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
    
    long long rec(vector<vector<pair<int, int>>> &graph, int v, vector<int> &dist, vector<long long> &memo) {
        long long &res = memo[v];
        if (res != -1)
            return res;
        
        res = 0;
        
        for (auto &[to, w] : graph[v])
            if (dist[v] < dist[to])
                res = (res + rec(graph, to, dist, memo)) % MOD;
        
        return res;
    }
    
public:
    int countRestrictedPaths(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back({ edge[1] - 1, edge[2] });
            graph[edge[1] - 1].push_back({ edge[0] - 1, edge[2] });
        }
        
        vector<int> dist = dijkstra(graph, graph.size() - 1);
        
        vector<long long> memo(graph.size(), -1);
        memo[0] = 1;
        return rec(graph, graph.size() - 1, dist, memo);
    }
};