class Solution {
    pair<int, int> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a) {
        int size = 1, maxSize = 0;
        
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            auto [toSize, toMaxSize] = dfs(graph, to, v, a);

            if (size && a[v] == a[to] && toSize)
                size += toSize;
            else
                size = 0;
            maxSize = max(maxSize, toMaxSize);
        }

        maxSize = max(maxSize, size);
        return { size, maxSize };
    }

public:
    int maximumSubtreeSize(vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, 0, -1, a).second;
    }
};