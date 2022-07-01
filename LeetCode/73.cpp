class Solution {
public:
    void setZeroes(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        int row0 = 1, col0 = 1;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x]) {
                    if (!y)
                        row0 = 0;
                    if (!x)
                        col0 = 0;
                    if (y && x)
                        a[y][0] = a[0][x] = 0;
                }
            }
        }
        
        for (int y = 1; y < h; y++)
            for (int x = 1; x < w; x++)
                if (!a[y][0] || !a[0][x])
                    a[y][x] = 0;
        
        if (!row0)
            for (int x = 0; x < w; x++)
                a[0][x] = 0;
        
        if (!col0)
            for (int y = 0; y < h; y++)
                a[y][0] = 0;
    }
};