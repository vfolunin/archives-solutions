class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int mask) {
        visited[v] = 1;
        for (int to : graph[v])
            if ((mask & (1 << to)) && !visited[to])
                dfs(graph, to, visited, mask);
    }
    
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
    bool isConnected(vector<vector<int>> &graph, int mask) {
        vector<int> visited(graph.size());
        for (int v = 0; v < graph.size(); v++) {
            if (mask & (1 << v)) {
                dfs(graph, v, visited, mask);
                return ones(mask) == count(visited.begin(), visited.end(), 1);
            }
        }
        return 0;
    }
    
    int diameter(vector<vector<int>> &dist, int mask) {
        int res = 0;        
        for (int a = 0; a < dist.size(); a++)
            for (int b = 0; b < dist.size(); b++)
                if ((mask & (1 << a)) && (mask & (1 << b)))
                    res = max(res, dist[a][b]);
        return res;
    }
    
public:
    vector<int> countSubgraphsForEachDiameter(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        
        vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
        for (int v = 0; v < vertexCount; v++)
            dist[v][v] = 0;
        
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
            dist[edge[0] - 1][edge[1] - 1] = 1;
            dist[edge[1] - 1][edge[0] - 1] = 1;
        }
        
        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);
        
        vector<int> res(vertexCount - 1);
        for (int mask = 0; mask < (1 << vertexCount); mask++)
            if (isConnected(graph, mask))
                if (int d = diameter(dist, mask); d)
                    res[d - 1]++;
        return res;
    }
};