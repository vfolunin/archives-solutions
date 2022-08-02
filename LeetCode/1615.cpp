class Solution {
public:
    int maximalNetworkRank(int vertexCount, vector<vector<int>> &edges) {
        vector<int> degree(vertexCount);
        set<pair<int, int>> edgeSet;
        
        for (vector<int> &edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            edgeSet.insert({ edge[0], edge[1] });
            edgeSet.insert({ edge[1], edge[0] });
        }
        
        int res = 0;
        for (int a = 0; a < vertexCount; a++)
            for (int b = a + 1; b < vertexCount; b++)
                res = max<int>(res, degree[a] + degree[b] - edgeSet.count({ a, b }));
        return res;
    }
};