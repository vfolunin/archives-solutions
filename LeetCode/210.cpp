class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order, bool &hasCycle) {
        visited[v] = 1;
        
        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, order, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }
        
        order.push_back(v);
        visited[v] = 2;
    }
    
public:
    vector<int> findOrder(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int> visited(vertexCount), order;
        bool hasCycle = 0;
        
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graph, v, visited, order, hasCycle);
        reverse(order.begin(), order.end());
        
        if (hasCycle)
            order.clear();
        
        return order;
    }
};