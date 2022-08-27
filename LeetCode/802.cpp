class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &safe) {
        visited[v] = 1;
        safe[v] = 1;
        
        for (int to : graph[v]) {
            if (visited[to] == 0) {
                dfs(graph, to, visited, safe);
                if (!safe[to])
                    safe[v] = 0;
            } else if (visited[to] == 1) {
                safe[v] = 0;
            } else {
                if (!safe[to])
                    safe[v] = 0;
            }
        }
        
        visited[v] = 2;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector<int> visited(graph.size()), safe(graph.size());
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(graph, v, visited, safe);
        
        vector<int> res;
        for (int v = 0; v < graph.size(); v++)
            if (safe[v])
                res.push_back(v);
        return res;
    }
};