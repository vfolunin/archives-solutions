class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        vector<int> degree(edges.size() + 1);
        for (auto &edge : edges) {
            if (++degree[edge[0] - 1] > 1)
                return edge[0];
            if (++degree[edge[1] - 1] > 1)
                return edge[1];
        }
        return 0;
    }
};