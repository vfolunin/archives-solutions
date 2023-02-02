class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &level, bool &hasCycle) {
        visited[v] = 1;
        level[v] = 1;

        for (int to : graph[v]) {
            if (visited[to] == 0) {
                dfs(graph, to, visited, level, hasCycle);
                level[v] = max(level[v], level[to] + 1);
            } else if (visited[to] == 1) {
                hasCycle = 1;
            } else {
                level[v] = max(level[v], level[to] + 1);
            }
        }

        visited[v] = 2;
    }

public:
    int minimumSemesters(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[1] - 1].push_back(edge[0] - 1);
        
        vector<int> visited(vertexCount), level(vertexCount);
        bool hasCycle = 0;
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graph, v, visited, level, hasCycle);
        
        if (hasCycle)
            return -1;
        return *max_element(level.begin(), level.end());
    }
};