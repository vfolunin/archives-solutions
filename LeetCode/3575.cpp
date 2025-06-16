class Solution {
    int getMask(int value) {
        int res = 0;
        for ( ; value; value /= 10) {
            if (res & (1 << (value % 10)))
                return -1;
            res |= 1 << (value % 10);
        }
        return res;
    }

    vector<int> dfs(vector<vector<int>> &graph, int v, int parent, vector<int> &a, long long &res) {
        vector<int> subtreeValues = { a[v] };
        for (int to : graph[v]) {
            if (to != parent) {
                vector<int> toValues = dfs(graph, to, v, a, res);
                subtreeValues.insert(subtreeValues.end(), toValues.begin(), toValues.end());
            }
        }
        
        vector<long long> maxSum(1 << 10);
        for (int value : subtreeValues) {
            int valueMask = getMask(value);
            if (valueMask == -1)
                continue;
            
            for (int mask = maxSum.size() - 1; mask >= 0; mask--)
                if ((mask & valueMask) == valueMask)
                    maxSum[mask] = max(maxSum[mask], maxSum[mask ^ valueMask] + value);
        }

        static const long long MOD = 1e9 + 7;
        res = (res + *max_element(maxSum.begin(), maxSum.end())) % MOD;

        return subtreeValues;
    }

public:
    int goodSubtreeSum(vector<int> &a, vector<int> &parent) {
        vector<vector<int>> graph(a.size());
        for (int v = 0; v < graph.size(); v++) {
            if (parent[v] != -1) {
                graph[parent[v]].push_back(v);
                graph[v].push_back(parent[v]);
            }
        }

        long long res = 0;
        dfs(graph, 0, -1, a, res);
        return res;
    }
};