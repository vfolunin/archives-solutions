class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited,
             vector<vector<unordered_set<int>>> &weights, int weightLimit) {
        visited[v] = 1;

        for (auto &[to, _] : graph[v])
            if (!visited[to])
                dfs(graph, to, visited, weights, weightLimit);
        
        weights[v][0] = { 0 };
        for (auto &[to, weight] : graph[v])
            for (int toLength = 0; 1 + toLength < weights[v].size(); toLength++)
                for (int toWeight : weights[to][toLength])
                    if (weight + toWeight < weightLimit)
                        weights[v][1 + toLength].insert(weight + toWeight);
    }

public:
    int maxWeight(int vertexCount, vector<vector<int>> &edges, int length, int weightLimit) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });
        
        vector<int> visited(vertexCount);
        vector weights(vertexCount, vector<unordered_set<int>>(length + 1));
        for (int v = 0; v < vertexCount; v++)
            if (!visited[v])
                dfs(graph, v, visited, weights, weightLimit);
        
        int res = -1;
        for (int v = 0; v < vertexCount; v++)
            for (int cur : weights[v][length])
                res = max(res, cur);
        return res;
    }
};