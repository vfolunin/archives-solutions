class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &depth, vector<double> &prob) {
        for (int to : graph[v]) {
            if (to == p)
                continue;

            depth[to] = depth[v] + 1;
            prob[to] = prob[v] / (graph[v].size() - (p != -1));
            dfs(graph, to, v, depth, prob);
        }
    }
    
public:
    double frogPosition(int vertexCount, vector<vector<int>> &edges, int time, int target) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<int> depth(vertexCount);
        vector<double> prob(vertexCount);
        prob[0] = 1;
        dfs(graph, 0, -1, depth, prob);
        
        target--;
        if (depth[target] > time || depth[target] < time && graph[target].size() > (target > 0))
            return 0;
        return prob[target];
    }
};