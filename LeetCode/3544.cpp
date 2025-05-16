class Solution {
    long long rec(vector<vector<int>> &graph, int v, int parent, int sign, int dist,
                  vector<int> &a, int minDist, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[v][sign + 1][dist];
        if (res != -1e18)
            return res;
        
        long long cur = sign * a[v];
        for (int to : graph[v])
            if (to != parent)
                cur += rec(graph, to, v, sign, min(dist + 1, 51), a, minDist, memo);
        res = max(res, cur);

        if (dist >= minDist) {
            long long cur = -sign * a[v];
            for (int to : graph[v])
                if (to != parent)
                    cur += rec(graph, to, v, -sign, 1, a, minDist, memo);
            res = max(res, cur);
        }

        return res;
    }

public:
    long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &a, int minDist) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector memo(graph.size(), vector(3, vector<long long>(52, -1e18)));
        return rec(graph, 0, -1, 1, 51, a, minDist, memo);
    }
};