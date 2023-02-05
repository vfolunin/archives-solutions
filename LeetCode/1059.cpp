class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }
        visited[v] = 2;
    }

public:
    bool leadsToDestination(int vertexCount, vector<vector<int>> &edges, int start, int finish) {
        vector<vector<int>> graph(vertexCount);
        vector<int> outDegree(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            outDegree[edge[0]]++;
        }

        vector<int> visited(vertexCount);
        bool hasCycle = 0;
        dfs(graph, start, visited, hasCycle);

        if (!visited[finish] || hasCycle)
            return 0;
        
        for (int v = 0; v < vertexCount; v++)
            if (visited[v] && !outDegree[v] && v != finish)
                return 0;
        
        return 1;
    }
};