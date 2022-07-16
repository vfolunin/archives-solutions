class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to = 0; to < graph.size(); to++)
            if (graph[v][to] && !visited[to])
                dfs(graph, to, visited);
    }
    
public:
    int findCircleNum(vector<vector<int>> &graph) {
        vector<int> visited(graph.size());
        int ccCount = 0;
        
        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v]) {
                ccCount++;
                dfs(graph, v, visited);
            }
        }
        
        return ccCount;
    }
};