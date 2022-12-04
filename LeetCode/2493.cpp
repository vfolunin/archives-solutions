class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite) {
        visited[v] = color;
        for (int to : graph[v]) {
            if (!visited[to])
                dfs(graph, to, visited, 3 - color, isBipartite);
            else if (visited[to] == color)
                isBipartite = 0;
        }
    }
    
    int bfs(vector<vector<int>> &graph, int v) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;
        
        dist[v] = 0;
        q.push(v);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        
        int res = 0;
        for (int d : dist)
            if (d != 1e9)
                res = max(res, d);
        return res;
    }
    
    int getGroupSize(vector<vector<int>> &graph, int v, vector<int> &visited) {
        bool isBipartite = 1;
        dfs(graph, v, visited, 1, isBipartite);
        
        if (!isBipartite)
            return -1;
        
        int res = 1;
        for (int v = 0; v < graph.size(); v++)
            if (visited[v] == 1 || visited[v] == 2)
                res = max(res, bfs(graph, v) + 1);
        
        for (int v = 0; v < graph.size(); v++)
            if (visited[v])
                visited[v] = 3;
        
        return res;
    }
    
public:
    int magnificentSets(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<int> visited(vertexCount);
        int res = 0;
        
        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v]) {
                int groupSize = getGroupSize(graph, v, visited);
                if (groupSize == -1)
                    return -1;
                res += groupSize;
            }
        }
        
        return res;
    }
};