class Solution {
    int dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        int res = 1;
        
        for (int to : graph[v])
            if (!visited[to])
                res += dfs(graph, to, visited);
        
        return res;
    }
    
public:
    long long countPairs(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(vertexCount);
        long long res = vertexCount * (vertexCount - 1LL) / 2;
        
        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v]) {
                long long ccSize = dfs(graph, v, visited);
                res -= ccSize * (ccSize - 1) / 2;
            }
        }
        
        return res;
    }
};