class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<int> rowMin(h, 1e9), colMax(w);
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rowMin[y] = min(rowMin[y], a[y][x]);
                colMax[x] = max(colMax[x], a[y][x]);
            }
        }
        
        vector<int> res;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x] == rowMin[y] && a[y][x] == colMax[x])
                    res.push_back(a[y][x]);
        
        return res;
    }
};