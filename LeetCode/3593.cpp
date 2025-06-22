class Solution {
    pair<int, long long> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a) {
        vector<pair<int, long long>> pairs;
        for (int to : graph[v])
            if (to != p)
                pairs.push_back(dfs(graph, to, v, a));
        
        int totalOps = 0;
        long long maxValue = 0;
        for (auto &[ops, value] : pairs) {
            totalOps += ops;
            maxValue = max(maxValue, value);
        }

        for (auto &[ops, value] : pairs) 
            totalOps += value != maxValue;

        return { totalOps, maxValue + a[v] };
    }

public:
    int minIncrease(int vertexCount, vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(graph, 0, -1, a).first;
    }
};