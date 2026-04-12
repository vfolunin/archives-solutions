class Solution {
public:
    vector<int> findDegrees(vector<vector<int>> &hasEdge) {
        vector<int> degree(hasEdge.size());
        for (int a = 0; a < degree.size(); a++)
            for (int b = 0; b < degree.size(); b++)
                degree[a] += hasEdge[a][b];
        return degree;
    }
};