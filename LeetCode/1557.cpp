class Solution {
public:
    vector<int> findSmallestSetOfVertices(int vertexCount, vector<vector<int>> &edges) {
        vector<int> inDegree(vertexCount);
        for (vector<int> &edge : edges)
            inDegree[edge[1]]++;

        vector<int> res;
        for (int v = 0; v < vertexCount; v++)
            if (!inDegree[v])
                res.push_back(v);
        return res;
    }
};