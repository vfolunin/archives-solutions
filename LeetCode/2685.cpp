class Solution {
    pair<int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        int vertices = 1, edges = 0;

        for (int to : graph[v]) {
            if (!visited[to]) {
                auto [toVertices, toEdges] = dfs(graph, to, visited);
                vertices += toVertices;
                edges += toEdges;
            }
            edges++;
        }

        return { vertices, edges };
    }
    
public:
    int countCompleteComponents(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(vertexCount);
        int res = 0;
        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v]) {
                auto [vertices, edges] = dfs(graph, v, visited);
                res += vertices * (vertices - 1) == edges;
            }
        }      
        return res;
    }
};