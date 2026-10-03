class Solution {
    pair<long long, unordered_map<int, pair<int, long long>>> dfs(vector<vector<int>> &graph, int v, int parent, int depth, vector<int> &group) {
        long long res = 0;
        unordered_map<int, pair<int, long long>> groupStats = { { group[v], { 1, depth } } };

        for (int to : graph[v]) {
            if (to == parent)
                continue;
            
            auto [toRes, toGroupStats] = dfs(graph, to, v, depth + 1, group);
            res += toRes;

            if (groupStats.size() < toGroupStats.size())
                groupStats.swap(toGroupStats);
            
            for (auto &[group, toStats] : toGroupStats) {
                auto &[count, sum] = groupStats[group];
                auto &[toCount, toSum] = toStats;

                res += count * toSum + toCount * sum - 2LL * depth * count * toCount;
                count += toCount;
                sum += toSum;
            }
        }

        return { res, move(groupStats) };
    }

public:
    long long interactionCosts(int vertexCount, vector<vector<int>> &edges, vector<int> &group) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return dfs(graph, 0, -1, 0, group).first;
    }
};