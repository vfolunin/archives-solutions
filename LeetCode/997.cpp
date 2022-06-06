class Solution {
public:
    int findJudge(int vertexCount, vector<vector<int>> &edges) {
        vector<int> outDegree(vertexCount), inDegree(vertexCount);
        for (vector<int> &edge : edges) {
            outDegree[edge[0] - 1]++;
            inDegree[edge[1] - 1]++;
        }
        
        for (int v = 0; v < vertexCount; v++)
            if (outDegree[v] == 0 && inDegree[v] == vertexCount - 1)
                return v + 1;
        
        return -1;
    }
};