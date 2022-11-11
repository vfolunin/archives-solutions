class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &time, vector<int> &visited) {
        visited[v] = time[v];
        
        int maxChild = 0;
        for (int to : graph[v]) {
            if (!visited[to])
                dfs(graph, to, time, visited);
            maxChild = max(maxChild, visited[to]);
        }
        
        visited[v] += maxChild;
    }
    
public:
    int minimumTime(int vertexCount, vector<vector<int>> &edges, vector<int> &time) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[1] - 1].push_back(edge[0] - 1);
        
        vector<int> visited(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graph, v, time, visited);
        
        return *max_element(visited.begin(), visited.end());
    }
};