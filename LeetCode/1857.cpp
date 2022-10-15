class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited,
             string &colors, vector<vector<int>> &res, int &hasCycle) {
        visited[v] = 1;
        
        res[v].resize(26);
        res[v][colors[v] - 'a'] = 1;
        
        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, colors, res, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
            
            for (int c = 0; c < 26; c++)
                res[v][c] = max(res[v][c], res[to][c] + (colors[v] - 'a' == c));
        }
        
        visited[v] = 2;
    }
public:
    int largestPathValue(string &colors, vector<vector<int>> &edges) {
        vector<vector<int>> graph(colors.size());
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back(edge[1]);
        
        vector<int> visited(graph.size());
        vector<vector<int>> res(graph.size());
        int hasCycle = 0;
        
        for (int v = 0; v < graph.size(); v++)
            if (!visited[v])
                dfs(graph, v, visited, colors, res, hasCycle);
        
        if (hasCycle)
            return -1;
        
        int maxRes = 0;
        for (vector<int> &row : res)
            maxRes = max(maxRes, *max_element(row.begin(), row.end()));
        return maxRes;
    }
};