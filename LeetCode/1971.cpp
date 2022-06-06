class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }
    
public:
    bool validPath(int vertexCount, vector<vector<int>> &edges, int source, int destination) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(vertexCount);
        dfs(graph, source, visited);
        return visited[destination];
    }
};