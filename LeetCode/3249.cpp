class Solution {
    pair<int, int> dfs(vector<vector<int>> &graph, int v, int p) {
        int size = 1, res = 0;
        int minChildSize = 1e9, maxChildSize = -1e9;

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            auto [childSize, childRes] = dfs(graph, to, v);
            size += childSize;
            minChildSize = min(minChildSize, childSize);
            maxChildSize = max(maxChildSize, childSize);
            res += childRes;
        }

        if (minChildSize == 1e9 || minChildSize == maxChildSize)
            res++;

        return { size, res };
    }

public:
    int countGoodNodes(vector<vector<int>> &edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(graph, 0, -1).second;
    }
};