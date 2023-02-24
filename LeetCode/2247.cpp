class Solution {
    int rec(vector<vector<pair<int, int>>> graph, int mask, int v, int k, vector<vector<int>> &memo) {
        int &res = memo[mask][v];
        if (res != -2)
            return res;
        
        if (!k)
            return res = 0;
        
        res = -1;
        for (auto &[to, weight] : graph[v]) {
            if (!(mask & (1 << to))) {
                int toRes = rec(graph, mask | (1 << to), to, k - 1, memo);
                if (toRes != -1)
                    res = max(res, toRes + weight);
            }
        }
        return res;
    }

public:
    int maximumCost(int vertexCount, vector<vector<int>> &edges, int k) {
        if (k + 1 > vertexCount)
            return -1;

        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }
        
        vector<vector<int>> memo(1 << vertexCount, vector<int>(vertexCount, -2));
        int res = -1;
        for (int v = 0; v < vertexCount; v++)
            res = max(res, rec(graph, 1 << v, v, k, memo));
        return res;
    }
};