class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int start, vector<vector<int>> &res) {
        visited[v] = 1;
        
        if (v != start)
            res[v].push_back(start);
        
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited, start, res);
    }
    
public:
    vector<vector<int>> getAncestors(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back(edge[1]);
        
        vector<vector<int>> res(vertexCount);
        for (int v = 0; v < vertexCount; v++) {
            vector<int> visited(vertexCount);
            dfs(graph, v, visited, v, res);
        }        
        return res;                
    }
};