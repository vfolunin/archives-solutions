class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order, bool &hasCycle) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, order, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }
        visited[v] = 2;
        order.push_back(v);
    }
    
public:
    vector<vector<int>> buildMatrix(int vertexCount, vector<vector<int>> &edgesY, vector<vector<int>> &edgesX) {
        vector<vector<int>> graphY(vertexCount);
        for (vector<int> &edge : edgesY)
            graphY[edge[0] - 1].push_back(edge[1] - 1);
        
        vector<vector<int>> graphX(vertexCount);
        for (vector<int> &edge : edgesX)
            graphX[edge[0] - 1].push_back(edge[1] - 1);
        
        vector<int> visited(vertexCount), orderY;
        bool hasCycle = 0;
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graphY, v, visited, orderY, hasCycle);
        
        if (hasCycle)
            return {};
        reverse(orderY.begin(), orderY.end());
        
        visited.assign(vertexCount, 0);
        vector<int> orderX;
        hasCycle = 0;
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graphX, v, visited, orderX, hasCycle);
        
        if (hasCycle)
            return {};
        reverse(orderX.begin(), orderX.end());
        
        vector<vector<int>> res(vertexCount, vector<int>(vertexCount));
        for (int v = 0; v < vertexCount; v++) {
            int y = find(orderY.begin(), orderY.end(), v) - orderY.begin();
            int x = find(orderX.begin(), orderX.end(), v) - orderX.begin();
            res[y][x] = v + 1;
        }
        return res;
    }
};