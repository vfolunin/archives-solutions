class Solution {
    int dfs(vector<vector<pair<int, int>>> &graph, int v, int p, int dist, int mod) {
        int divisibleCount = dist && dist % mod == 0;
        vector<int> childDivisibleCount;

        for (auto [to, weight] : graph[v]) {
            if (to == p)
                continue;

            int toDivisibleCount = dfs(graph, to, v, dist + weight, mod);

            if (dist)
                divisibleCount += toDivisibleCount;
            else
                childDivisibleCount.push_back(toDivisibleCount);
        }

        if (dist)
            return divisibleCount;
        
        int res = 0;
        for (int i = 0; i < childDivisibleCount.size(); i++)
            for (int j = i + 1; j < childDivisibleCount.size(); j++)
                res += childDivisibleCount[i] * childDivisibleCount[j];
        return res;
    }

public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int mod) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<int> res(graph.size());
        for (int v = 0; v < res.size(); v++)
            res[v] = dfs(graph, v, -1, 0, mod);
        return res;
    }
};