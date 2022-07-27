class Solution {
    int dfs(vector<vector<pair<int, int>>> &graph, int v, int p) {
        int res = 0;
        for (auto &[to, w] : graph[v])
            if (to != p)
                res += w + dfs(graph, to, v);
        return res;
    }
    
public:
    int minReorder(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], 1 });
            graph[edge[1]].push_back({ edge[0], 0 });
        }
        return dfs(graph, 0, -1);
    }
};