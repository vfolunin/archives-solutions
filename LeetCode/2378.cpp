class Solution {
    pair<long long, long long> dfs(vector<vector<pair<int, int>>> &graph, int v) {
        long long score = 0, maxAdd = 0;
        for (auto &[to, weight] : graph[v]) {
            auto [toScore0, toScore1] = dfs(graph, to);
            score += toScore1;
            maxAdd = max(maxAdd, toScore0 + weight - toScore1);
        }
        return { score, score + maxAdd };
    }

public:
    long long maxScore(vector<vector<int>> &parents) {
        vector<vector<pair<int, int>>> graph(parents.size());
        for (int v = 1; v < parents.size(); v++)
            graph[parents[v][0]].push_back({ v, parents[v][1] });

        auto [score0, score1] = dfs(graph, 0);
        return max(score0, score1);
    }
};