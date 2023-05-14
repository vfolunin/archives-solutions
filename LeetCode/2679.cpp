class Solution {
public:
    int matrixSum(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        for (vector<int> &row : a)
            sort(row.begin(), row.end());
        
        vector<int> colMax(w);
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                colMax[x] = max(colMax[x], a[y][x]);
        
        return accumulate(colMax.begin(), colMax.end(), 0);
    }
};