class Solution {
    pair<int, vector<int>> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &group, vector<int> &totalCount, long long &res) {
        int size = 1;
        vector<int> count(20);
        count[group[v]]++;

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            auto [toSize, toCount] = dfs(graph, to, v, group, totalCount, res);
            size += toSize;
            for (int i = 0; i < count.size(); i++) {
                count[i] += toCount[i];
                res += 1LL * toCount[i] * (totalCount[i] - toCount[i]);
            }
        }

        return { size, count };
    }

public:
    long long interactionCosts(int vertexCount, vector<vector<int>> &edges, vector<int> &group) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> totalCount(20);
        for (int &group : group)
            totalCount[--group]++;
        
        long long res = 0;
        dfs(graph, 0, -1, group, totalCount, res);
        return res;
    }
};