class Solution {
    void dfs(vector<vector<int>> &graph, int v, int parent, vector<int> &depth) {
        depth[v] = parent != -1 ? depth[parent] + 1 : 1;
        for (int to : graph[v])
            dfs(graph, to, v, depth);
    }

public:
    long long weightedSum(vector<int> &parent, vector<int> &values) {
        vector<vector<int>> graph(parent.size());
        for (int v = 1; v < graph.size(); v++)
            graph[parent[v]].push_back(v);
        
        vector<int> depth(graph.size());
        dfs(graph, 0, -1, depth);
        int height = *max_element(depth.begin(), depth.end());

        long long res = 0;
        for (int v = 0; v < graph.size(); v++)
            res += values[v] * (height - depth[v] + 1LL);
        return res;
    }
};