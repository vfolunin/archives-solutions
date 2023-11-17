class Solution {
    pair<long long, long long> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a) {
        long long validSum = 0, totalSum = 0;
        bool isLeaf = 1;

        for (int to : graph[v]) {
            if (to == p)
                continue;

            auto [childValidSum, childTotalSum] = dfs(graph, to, v, a);
            validSum += childValidSum;
            totalSum += childTotalSum;
            isLeaf = 0;
        }

        if (!isLeaf && a[v])
            validSum = max(a[v] + validSum, totalSum);

        return { validSum, totalSum + a[v] };
    }

public:
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, 0, -1, a).first;
    }
};