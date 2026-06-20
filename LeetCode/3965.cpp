class Solution {
    long long dfs(vector<vector<int>> &graph, int v, int parent, vector<int> &time) {
        int childCount = 0;
        long long minTime = 1e18, maxTime = -1e18;

        for (int to : graph[v]) {
            if (to == parent)
                continue;

            childCount++;
            long long childTime = dfs(graph, to, v, time);
            minTime = min(minTime, childTime);
            maxTime = max(maxTime, childTime);
        }

        return time[v] + (childCount ? 2 * maxTime - minTime : 0);
    }

public:
    long long finishTime(int vertexCount, vector<vector<int>> &edges, vector<int> &time) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, 0, -1, time);
    }
};