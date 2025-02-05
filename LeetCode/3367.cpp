class Solution {
    pair<long long, long long> dfs(vector<vector<pair<int, int>>> &graph, int v, int parent, int limit) {
        long long sum0 = 0, sum1 = 0;
        vector<pair<long long, long long>> childSums;

        for (auto &[to, weight] : graph[v]) {
            if (to == parent)
                sum1 += weight;
            else
                childSums.push_back(dfs(graph, to, v, limit));
        }

        sort(childSums.begin(), childSums.end(), [](auto &a, auto &b) {
            return a.first - a.second < b.first - b.second;
        });

        for (int i = 0; i < childSums.size(); i++) {
            if (childSums[i].first >= childSums[i].second || !limit) {
                sum0 += childSums[i].first;
                sum1 += childSums[i].first;
            } else {
                sum0 += childSums[i].second;
                sum1 += limit > 1 ? childSums[i].second : childSums[i].first;
                limit--;
            }
        }

        return { sum0, sum1 };
    }

public:
    long long maximizeSumOfWeights(vector<vector<int>> &edges, int limit) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        return dfs(graph, 0, -1, limit).first;
    }
};