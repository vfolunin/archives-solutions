class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }
    
public:
    int makeConnected(int vertexCount, vector<vector<int>> &edges) {
        if (edges.size() < vertexCount - 1)
            return -1;
        
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(vertexCount);
        int ccCount = 0;
        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v]) {
                dfs(graph, v, visited);
                ccCount++;
            }
        }
        
        return ccCount - 1;
    }
};