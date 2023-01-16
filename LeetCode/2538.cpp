class Solution {
    pair<long long, long long> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &price, long long &res) {
        pair<long long, long long> cost = { 0, price[v] };

        for (int to : graph[v]) {
            if (to == p)
                continue;

            pair<long long, long long> childCost = dfs(graph, to, v, price, res);
            res = max({ res, cost.first + childCost.second, cost.second + childCost.first });
            cost.first = max(cost.first, price[v] + childCost.first);
            cost.second = max(cost.second, price[v] + childCost.second);
        }

        return cost;
    }

public:
    long long maxOutput(int vertexCount, vector<vector<int>> &edges, vector<int> &price) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long res = 0;
        dfs(graph, 0, -1, price, res);
        return res;
    }
};