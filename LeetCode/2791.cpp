class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, int mask, unordered_map<int, int> &count, long long &res) {
        if (auto it = count.find(mask); it != count.end())
            res += it->second;
        for (int bit = 0; bit < 26; bit++)
            if (auto it = count.find(mask ^ (1 << bit)); it != count.end())
                res += it->second;

        count[mask]++;

        for (auto &[to, bit] : graph[v])
            dfs(graph, to, mask ^ (1 << bit), count, res);
    }

public:
    long long countPalindromePaths(vector<int> &parent, string &s) {
        vector<vector<pair<int, int>>> graph(parent.size());
        for (int i = 1; i < parent.size(); i++)
            graph[parent[i]].push_back({ i, s[i] - 'a' });

        unordered_map<int, int> count;
        long long res = 0;
        dfs(graph, 0, 0, count, res);

        return res;
    }
};