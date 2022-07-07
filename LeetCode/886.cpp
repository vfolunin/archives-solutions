class Solution {
    bool dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
        visited[v] = color;
        for (int to : graph[v])
            if (!visited[to] && !dfs(graph, to, visited, 3 - color) || visited[to] == color)
                return 0;
        return 1;
    }
    
public:
    bool possibleBipartition(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
    
        vector<int> visited(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v] && !dfs(graph, v, visited, 1))
                return 0;

        return 1;
    }
};