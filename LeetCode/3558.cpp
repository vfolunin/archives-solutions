class Solution {
    int dfs(vector<vector<int>> &graph, int v, int p) {
        int res = 0;
        for (int to : graph[v])
            if (to != p)
                res = max(res, 1 + dfs(graph, to, v));
        return res;
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int assignEdgeWeights(vector<vector<int>> &edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1); 
        }

        return binPow(2, dfs(graph, 0, -1) - 1, 1e9 + 7);
    }
};
