class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &bipartite) {
        visited[v] = color;
        for (int to : graph[v]) {
            if (!visited[to])
                dfs(graph, to, visited, 3 - color, bipartite);
            else if (visited[to] == color)
                bipartite = 0;
        }
    }
    
public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> visited(graph.size());
        bool bipartite = 1;
        for (int v = 0; bipartite && v < graph.size(); v++)
            if (!visited[v])
                dfs(graph, v, visited, 1, bipartite);
        return bipartite;
    }
};