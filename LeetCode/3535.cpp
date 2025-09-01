class Solution {
    static const long long MOD = 1e9 + 7;

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long n) {
        return binPow(n, MOD - 2, MOD);
    }

    void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &factor) {
        for (auto &[to, f] : graph[v]) {
            factor[to] = 1LL * factor[v] * f % MOD;
            dfs(graph, to, factor);
        }
    }

public:
    vector<int> queryConversions(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });

        vector<int> factor(graph.size());
        factor[0] = 1;

        dfs(graph, 0, factor);

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = 1LL * inv(factor[queries[i][0]]) * factor[queries[i][1]] % MOD;
        return res;
    }
};