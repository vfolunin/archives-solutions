class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }
    
public:
    int minScore(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<int> visitedA(vertexCount);
        dfs(graph, 0, visitedA);
        
        vector<int> visitedB(vertexCount);
        dfs(graph, vertexCount - 1, visitedB);
        
        int res = 1e9;
        for (vector<int> &edge : edges)
            if (visitedA[edge[0] - 1] && visitedB[edge[1] - 1])
                res = min(res, edge[2]);
        return res;
    }
};