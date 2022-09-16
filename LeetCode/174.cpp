class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> res(h, vector<int>(w, 1e9));
        res[h - 1][w - 1] = max(-a[h - 1][w - 1], 0);
        
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                if (y + 1 < h)
                    res[y][x] = min(res[y][x], max(res[y + 1][x] - a[y][x], 0));
                if (x + 1 < w)
                    res[y][x] = min(res[y][x], max(res[y][x + 1] - a[y][x], 0));
            }
        }
        
        return res[0][0] + 1;
    }
};