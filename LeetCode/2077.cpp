class Solution {
public:
    int numberOfPaths(int vertexCount, vector<vector<int>> &edges) {
        vector<unordered_set<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            if (edge[0] > edge[1])
                swap(edge[0], edge[1]);
            graph[edge[0] - 1].insert(edge[1] - 1);
        }

        int res = 0;
        for (int a = 0; a < vertexCount; a++)
            for (int b : graph[a])
                for (int c : graph[b])
                    res += graph[a].count(c);
        return res;
    }
};