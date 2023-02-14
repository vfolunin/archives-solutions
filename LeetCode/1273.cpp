class Solution {
    tuple<int, int, int> dfs(vector<vector<int>> &graph, int v, vector<int> &value) {
        int sum = value[v], count = 1, delCount = 0;
        
        for (int to : graph[v]) {
            auto [toSum, toCount, toDelCount] = dfs(graph, to, value);
            sum += toSum;
            count += toCount;
            delCount += toDelCount;
        }

        if (!sum)
            delCount = count;

        return { sum, count, delCount };
    }

public:
    int deleteTreeNodes(int vertexCount, vector<int> &parent, vector<int> &value) {
        vector<vector<int>> graph(vertexCount);
        for (int v = 1; v < vertexCount; v++)
            graph[parent[v]].push_back(v);
        
        auto [sum, count, delCount] = dfs(graph, 0, value);
        return vertexCount - delCount;
    }
};