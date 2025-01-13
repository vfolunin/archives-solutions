class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }

    bool can(int vertexCount, vector<vector<int>> &edges, int limit) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            if (edge[2] <= limit)
                graph[edge[1]].push_back(edge[0]);
        
        vector<int> visited(vertexCount);
        dfs(graph, 0, visited);
        return !count(visited.begin(), visited.end(), 0);
    }

public:
    int minMaxWeight(int vertexCount, vector<vector<int>> &edges, int _) {
        int l = -1, r = 1e7;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(vertexCount, edges, m))
                r = m;
            else
                l = m;
        }
        return r != 1e7 ? r : -1;
    }
};