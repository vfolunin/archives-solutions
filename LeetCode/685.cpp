class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        for (int to : graph[v])
            dfs(graph, to, visited);
    }
    
    bool checkTree(vector<vector<int>> &edges, int redundantIndex) {
        int vertexCount = edges.size();
        
        vector<int> parent(vertexCount, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (i == redundantIndex)
                continue;
            if (parent[edges[i][1] - 1] == -1)
                parent[edges[i][1] - 1] = edges[i][0] - 1;
            else
                return 0;
        }
        
        if (count(parent.begin(), parent.end(), -1) != 1)
            return 0;
        
        int root;
        vector<vector<int>> graph(vertexCount);
        for (int v = 0; v < vertexCount; v++) {
            if (parent[v] == -1)
                root = v;
            else
                graph[parent[v]].push_back(v);
        }
        
        vector<int> visited(vertexCount);
        dfs(graph, root, visited);
        return find(visited.begin(), visited.end(), 0) == visited.end();
    }
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        for (int i = edges.size() - 1; 1; i--)
            if (checkTree(edges, i))
                return edges[i];
    }
};