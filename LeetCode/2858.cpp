class Solution {
    int dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        int res = 0;
        
        for (auto &[to, isGood] : graph[v])
            if (!visited[to])
                res += dfs(graph, to, visited) + !isGood;
        
        return res;
    }

    void dfs2(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited, vector<int> &res, int prevRes) {
        visited[v] = 1;
        if (v)
            res[v] = prevRes;
        
        for (auto &[to, isGood] : graph[v])
            if (!visited[to])
                dfs2(graph, to, visited, res, prevRes + (isGood ? 1 : -1));
    }

public:
    vector<int> minEdgeReversals(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], 1 });
            graph[edge[1]].push_back({ edge[0], 0 });
        }
        
        vector<int> visited(vertexCount);
        vector<int> res(vertexCount);
        res[0] = dfs(graph, 0, visited);
        
        visited.assign(vertexCount, 0);
        dfs2(graph, 0, visited, res, res[0]);        
        return res;
    }
};