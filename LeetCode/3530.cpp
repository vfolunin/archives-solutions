class Solution {
    int rec(vector<vector<int>> &graph, int mask, int i, vector<int> &inDegree, vector<int> &a, vector<int> &memo) {
        int &res = memo[mask];
        if (res != -1)
            return res;
            
        res = 0;
        if (i == graph.size())
            return res;

        for (int v = 0; v < graph.size(); v++) {
            if ((mask & (1 << v)) && !inDegree[v]) {
                for (int to : graph[v])
                    inDegree[to]--;
                res = max(res, (i + 1) * a[v] + rec(graph, mask ^ (1 << v), i + 1, inDegree, a, memo));
                for (int to : graph[v])
                    inDegree[to]++;
            }
        }
        return res;
    }

public:
    int maxProfit(int vertexCount, vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(vertexCount);
        vector<int> inDegree(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        vector<int> memo(1 << vertexCount, -1);
        return rec(graph, (1 << vertexCount) - 1, 0, inDegree, a, memo);
    }
};