class Solution {
public:
    long long maxScore(long long vertexCount, vector<vector<int>> &edges) {
        return vertexCount * (2 * vertexCount * vertexCount + 3 * vertexCount - 11) / 6 + (edges.size() < vertexCount ? 1 : 3);
    }
};