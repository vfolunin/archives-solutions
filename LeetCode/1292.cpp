class Solution {
    int getSum(vector<vector<int>> &p, int yl, int xl, int yr, int xr) {
        int res = p[yr][xr];
        if (yl)
            res -= p[yl - 1][xr];
        if (xl)
            res -= p[yr][xl - 1];
        if (yl && xl)
            res += p[yl - 1][xl - 1];
        
        return res;
    }
    
public:
    int maxSideLength(vector<vector<int>> &a, int threshold) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> p = a;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
        
        for (int size = min(h, w); size; size--)
            for (int y = 0; y + size <= h; y++)
                for (int x = 0; x + size <= w; x++)
                    if (getSum(p, y, x, y + size - 1, x + size - 1) <= threshold)
                        return size;
        return 0;
    }
};