class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<int> rowMax(h, 0), colMax(w, 0);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rowMax[y] = max(rowMax[y], a[y][x]);
                colMax[x] = max(colMax[x], a[y][x]);
            }
        }
        
        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += min(rowMax[y], colMax[x]) - a[y][x];
        return res;
    }
};