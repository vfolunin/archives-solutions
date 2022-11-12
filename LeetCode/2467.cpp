class Solution {
    void dfsDist(vector<vector<int>> &graph, int v, int p, vector<int> &dist) {
        dist[v] = p == -1 ? 0 : dist[p] + 1;
        for (int to : graph[v])
            if (to != p)
                dfsDist(graph, to, v, dist);
    }
    
    void dfsSum(vector<vector<int>> &graph, int v, int p, vector<int> &cost, vector<int> &sum) {
        sum[v] = cost[v] + (p == -1 ? 0 : sum[p]);
        for (int to : graph[v])
            if (to != p)
                dfsSum(graph, to, v, cost, sum);
    }
    
public:
    int mostProfitablePath(vector<vector<int>> &edges, int b, vector<int> &cost) {
        vector<vector<int>> graph(cost.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> distA(graph.size());
        dfsDist(graph, 0, -1, distA);
        
        vector<int> distB(graph.size());
        dfsDist(graph, b, -1, distB);

        for (int v = 0; v < graph.size(); v++) {
            if (distA[v] + distB[v] == distA[b]) {
                if (distA[v] > distB[v])
                    cost[v] = 0;
                else if (distA[v] == distB[v])
                    cost[v] /= 2;
            }
        }
        
        vector<int> sum(graph.size());
        dfsSum(graph, 0, -1, cost, sum);
        
        int res = -2e9;
        for (int v = 1; v < graph.size(); v++)
            if (graph[v].size() == 1)
                res = max(res, sum[v]);
        return res;
    }
};