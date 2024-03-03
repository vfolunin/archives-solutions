class Solution {
    vector<long long> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a, int xorValue) {
        long long sum = max(a[v], a[v] ^ xorValue);
        long long delta = abs(a[v] - (a[v] ^ xorValue));
        int xorParity = a[v] < (a[v] ^ xorValue);

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            vector<long long> toRes = dfs(graph, to, v, a, xorValue);

            sum += max(toRes[0], toRes[1]);
            delta = min(delta, abs(toRes[0] - toRes[1]));
            xorParity ^= toRes[0] < toRes[1];
        }

        vector<long long> res(2, sum);
        res[xorParity ^ 1] -= delta;
        return res;
    }

public:
    long long maximumValueSum(vector<int> &a, int xorValue, vector<vector<int>> &edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(graph, 0, -1, a, xorValue)[0];
    }
};