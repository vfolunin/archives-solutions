class Solution {
    const long long MOD = 1e9 + 7;

    void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &res) {
        for (auto &[to, weight] : graph[v]) {
            res[to] = 1LL * res[v] * weight % MOD;
            dfs(graph, to, res);
        }
    }

public:
    vector<int> baseUnitConversions(vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });

        vector<int> res(graph.size());
        res[0] = 1;
        dfs(graph, 0, res);
        return res;
    }
};