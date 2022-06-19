class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
        visited[v] = 1;
        for (int &to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }
        visited[v] = 2;
    }
    
public:
    bool canFinish(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back(edge[1]);
        
        vector<int> visited(vertexCount);
        bool hasCycle = 0;
        
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(graph, v, visited, hasCycle);
        
        return !hasCycle;
    }
};