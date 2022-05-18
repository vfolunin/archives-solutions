class Solution {
    vector<vector<int>> g;
    vector<int> visited, depth, upDepth;
    vector<vector<int>> bridges;

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];

        for (int to : g[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (upDepth[to] > depth[v])
                    bridges.push_back({ v, to });
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int vertexCount, vector<vector<int>> &edges) {
        g.resize(vertexCount);
        for (vector<int> &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
        
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
        
        return bridges;
    }
};