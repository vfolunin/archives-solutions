class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &time) {
        if (p != -1)
            time[v] += time[p];
        
        for (int to : graph[v])
            dfs(graph, to, v, time);
    }
    
public:
    int numOfMinutes(int vertexCount, int root, vector<int> &parent, vector<int> &time) {
        vector<vector<int>> graph(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            if (parent[v] != -1)
                graph[parent[v]].push_back(v);
        
        dfs(graph, root, -1, time);
        return *max_element(time.begin(), time.end());
    }
};