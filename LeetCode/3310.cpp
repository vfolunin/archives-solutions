class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited);
    }

public:
    vector<int> remainingMethods(int vertexCount, int start, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        vector<vector<int>> graphR(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graphR[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(vertexCount);
        dfs(graph, start, visited);

        vector<int> visitedR(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            if (visited[v] && !visitedR[v])
                dfs(graphR, v, visitedR);
        
        bool ok = visited == visitedR;

        vector<int> res;
        for (int v = 0; v < vertexCount; v++)
            if (!ok || !visited[v])
                res.push_back(v);
        return res;
    }
};