class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &color) {
        set<int> colors = { 1, 2, 3, 4 };
        for (int to : graph[v])
            colors.erase(color[to]);
        color[v] = *colors.begin();
        
        for (int to : graph[v])
            if (!color[to])
                dfs(graph, to, color);
    }
    
public:
    vector<int> gardenNoAdj(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<int> color(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            if (!color[v])
                dfs(graph, v, color);
        return color;
    }
};