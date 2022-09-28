class Solution {
    const long long MOD = 1e9 + 7;
    
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long x) {
        return binPow(x, MOD - 2, MOD);
    }
    
    vector<long long> precalcFactorials() {
        vector<long long> memo(1e5);
        memo[0] = 1;
        for (int i = 1; i < memo.size(); i++)
            memo[i] = memo[i - 1] * i % MOD;
        return memo;
    }

    long long factorial(int n) {
        static vector<long long> memo = precalcFactorials();
        return memo[n];
    }

    long long c(int n, int k) {
        return factorial(n) * inv(factorial(k)) % MOD * inv(factorial(n - k)) % MOD;
    }
    
    pair<long long, long long> dfs(vector<vector<int>> &graph, int v) {
        long long size = 1, ways = 1;
        for (int to : graph[v]) {
            auto [toSize, toWays] = dfs(graph, to);
            ways = ways * c(size + toSize - 1, toSize) % MOD * toWays % MOD;
            size += toSize;
        }
        return { size, ways };
    }
    
public:
    int waysToBuildRooms(vector<int> &from) {
        vector<vector<int>> graph(from.size());
        for (int v = 1; v < graph.size(); v++)
            graph[from[v]].push_back(v);
        return dfs(graph, 0).second;
    }
};