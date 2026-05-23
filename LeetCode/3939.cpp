class Solution {
    static inline const int MOD = 1e9 + 7;

    void rec(vector<vector<int>> &graph, int v, vector<int> &value, int divisor, vector<vector<vector<long long>>> &ways) {
        ways[v][0][0] = 1;
        ways[v][1][value[v]] = 1;

        for (int to : graph[v]) {
            rec(graph, to, value, divisor, ways);

            vector nextWays(2, vector<long long>(divisor, 0));
            for (int vMod = 0; vMod < divisor; vMod++) {
                for (int toMod = 0; toMod < divisor; toMod++) {
                    int mod = (vMod + toMod) % divisor;
                    nextWays[0][mod] = (nextWays[0][mod] + ways[v][0][vMod] * (ways[to][0][toMod] + ways[to][1][toMod])) % MOD;
                    nextWays[1][mod] = (nextWays[1][mod] + ways[v][1][vMod] * ways[to][0][toMod]) % MOD;
                }
            }
            ways[v].swap(nextWays);
        }
    }

public:
    int countValidSubsets(vector<int> &parent, vector<int> &value, int divisor) {
        vector<vector<int>> graph(parent.size());
        for (int v = 1; v < parent.size(); v++)
            graph[parent[v]].push_back(v);

        for (int &value : value)
            value %= divisor;
        
        vector ways(graph.size(), vector(2, vector<long long>(divisor, 0)));
        rec(graph, 0, value, divisor, ways);
        return (ways[0][0][0] + ways[0][1][0] + MOD - 1) % MOD;
    }
};