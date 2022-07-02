class Solution {
public:
    long long maximumImportance(int vertexCount, vector<vector<int>> &edges) {
        vector<int> degree(vertexCount);
        for (vector<int> &edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        sort(degree.begin(), degree.end());
        
        long long res = 0;
        for (int i = 0; i < vertexCount; i++)
            res += (i + 1LL) * degree[i];
        
        return res;
    }
};