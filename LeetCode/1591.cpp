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
    bool isPrintable(vector<vector<int>> &a) {
        vector<int> minY(61, 1e9), minX(61, 1e9), maxY(61, -1e9), maxX(61, -1e9);
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                minY[a[y][x]] = min(minY[a[y][x]], y);
                minX[a[y][x]] = min(minX[a[y][x]], x);
                maxY[a[y][x]] = max(maxY[a[y][x]], y);
                maxX[a[y][x]] = max(maxX[a[y][x]], x);
            }
        }
        
        vector<vector<int>> graph(61);
        for (int v = 0; v < minY.size(); v++) {
            if (minY[v] == 1e9)
                continue;
            
            for (int y = minY[v]; y <= maxY[v]; y++)
                for (int x = minX[v]; x <= maxX[v]; x++)
                    if (a[y][x] != v)
                        graph[v].push_back(a[y][x]);
        }
        
        vector<int> visited(minY.size());
        bool hasCycle = 0;
        for (int v = 0; v < minY.size(); v++)
            if (!visited[v])
                dfs(graph, v, visited, hasCycle);
        
        return !hasCycle;
    }
};