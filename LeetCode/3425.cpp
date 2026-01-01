class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, int parent,
             vector<int> &value, vector<int> &prefixSum, int from,
             unordered_map<int, vector<int>> &valueDepth, vector<int> &res) {
        if (auto it = valueDepth.find(value[v]); it != valueDepth.end())
            from = max(from, it->second.empty() ? 0 : it->second.back() + 1);
        valueDepth[value[v]].push_back(prefixSum.size() - 1);

        int curLength = prefixSum.back() - prefixSum[from];
        int curVertexCount = prefixSum.size() - from;
        if (res[0] < curLength)
            res = { curLength, curVertexCount };
        else if (res[0] == curLength)
            res[1] = min(res[1], curVertexCount);

        for (auto &[to, weight] : graph[v]) {
            if (to != parent) {
                prefixSum.push_back(prefixSum.back() + weight);
                dfs(graph, to, v, value, prefixSum, from, valueDepth, res);
                prefixSum.pop_back();
            }
        }

        valueDepth[value[v]].pop_back();
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &value) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<int> prefixSum(1);
        unordered_map<int, vector<int>> valueDepth;
        vector<int> res = { 0, 1 };
        dfs(graph, 0, -1, value, prefixSum, 0, valueDepth, res);
        return res;
    }
};