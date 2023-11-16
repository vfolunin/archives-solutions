class Solution {
public:
    int findChampion(int vertexCount, vector<vector<int>> &edges) {
        vector<int> inDegree(vertexCount);
        for (vector<int> &edge : edges)
            inDegree[edge[1]]++;
        
        if (count(inDegree.begin(), inDegree.end(), 0) == 1)
            return find(inDegree.begin(), inDegree.end(), 0) - inDegree.begin();
        else
            return -1;
    }
};