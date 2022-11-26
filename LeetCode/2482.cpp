class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> rowCount(h, vector<int>(2));
        vector<vector<int>> colCount(w, vector<int>(2));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rowCount[y][a[y][x]]++;
                colCount[x][a[y][x]]++;
            }
        }
        
        vector<vector<int>> res(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[y][x] = rowCount[y][1] + colCount[x][1] - rowCount[y][0] - colCount[x][0];        
        return res;
    }
};