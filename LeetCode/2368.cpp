class Solution {
    int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        int size = 1;
        
        for (int to : graph[v])
            if (!visited[to])
                size += dfs(graph, to, visited);
        
        return size;
    }
    
public:
    int reachableNodes(int vertexCount, vector<vector<int>> &edges, vector<int> &restricted) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(vertexCount);
        for (int v : restricted)
            visited[v] = 1;
        
        return dfs(graph, 0, visited);
    }
};