class Solution {
public:
    int projectionArea(vector<vector<int>> &a) {
        int size = a.size();
        vector<int> maxRow(size), maxCol(size);
        
        int res = 0;
        
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                res += a[y][x] > 0;
                maxRow[y] = max(maxRow[y], a[y][x]);
                maxCol[x] = max(maxCol[x], a[y][x]);
            }
        }
        
        for (int i = 0; i < size; i++)
            res += maxRow[i] + maxCol[i];
        
        return res;
    }
};