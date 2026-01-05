class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, int parent,
             vector<int> &value, vector<int> &prefixSum, int from, int repValue,
             unordered_map<int, vector<int>> &valueDepth, vector<int> &res) {
        if (auto it = valueDepth.find(value[v]); it != valueDepth.end() && !it->second.empty()) {
            if (repValue == -1) {
                repValue = value[v];
            } else if (valueDepth[value[v]].back() < valueDepth[repValue][valueDepth[repValue].size() - 2]) {
                from = max(from, valueDepth[value[v]].back() + 1);
            } else {
                from = valueDepth[repValue][valueDepth[repValue].size() - 2] + 1;
                repValue = value[v];
            }
        }
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
                dfs(graph, to, v, value, prefixSum, from, repValue, valueDepth, res);
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
        dfs(graph, 0, -1, value, prefixSum, 0, -1, valueDepth, res);
        return res;
    }
};