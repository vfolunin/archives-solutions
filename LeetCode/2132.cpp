class Solution {
    void precalcSum(vector<vector<int>> &p) {
        for (int y = 0; y < p.size(); y++) {
            for (int x = 0; x < p[0].size(); x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
    }
    
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
    bool possibleToStamp(vector<vector<int>> &a, int stampH, int stampW) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> p = a;
        precalcSum(p);
        
        vector<vector<int>> mark(h, vector<int>(w));
        for (int y = 0; y + stampH <= h; y++)
            for (int x = 0; x + stampW <= w; x++)
                mark[y][x] = !getSum(p, y, x, y + stampH - 1, x + stampW - 1);        
        precalcSum(mark);
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (!a[y][x] && !getSum(mark, max(0, y - stampH + 1), max(0, x - stampW + 1), y, x))
                    return 0;
        return 1;
    }
};