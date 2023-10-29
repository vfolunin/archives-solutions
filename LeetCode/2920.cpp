class Solution {
    int dfs(vector<vector<int>> &graph, int v, int p, int ops, vector<int> &a, int sub, vector<vector<int>> &memo) {
        if (ops >= memo[0].size())
            return 0;

        int &res = memo[v][ops];
        if (res != -1)
            return res;
        
        int res0 = (a[v] >> ops) - sub;
        int res1 = a[v] >> (ops + 1);

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            res0 += dfs(graph, to, v, ops, a, sub, memo);
            res1 += dfs(graph, to, v, ops + 1, a, sub, memo);
        }

        return res = max(res0, res1);
    }

public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &a, int sub) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> memo(graph.size(), vector<int>(14, -1));
        return dfs(graph, 0, -1, 0, a, sub, memo);
    }
};