class Solution {
    pair<int, vector<long long>> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a, vector<long long> &res) {
        int size = 1;
        vector<long long> values = { a[v] };

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            auto [toSize, toValues] = dfs(graph, to, v, a, res);
            size += toSize;
            values.insert(values.end(), toValues.begin(), toValues.end());
        }

        if (size < 3) {
            res[v] = 1;
        } else {
            sort(values.begin(), values.end());
            res[v] = max(0LL, values.back() * max(values[0] * values[1], values[values.size() - 3] * values[values.size() - 2]));
            if (values.size() > 5)
                values.erase(values.begin() + 2, values.end() - 3);
        }
        return { size, values };
    }

public:
    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<long long> res(graph.size());
        dfs(graph, 0, -1, a, res);
        return res;
    }
};