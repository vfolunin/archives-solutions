class Solution {
    int getSum(vector<vector<int>> &p, int yl, int xl, int yr, int xr) {
        yl = max(yl, 0);
        xl = max(xl, 0);
        yr = min<int>(yr, p.size() - 1);
        xr = min<int>(xr, p[0].size() - 1);
        
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &a, int k) {
        vector<vector<int>> p = a;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
        
        vector<vector<int>> res(a.size(), vector<int>(a[0].size()));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res[y][x] = getSum(p, y - k, x - k, y + k, x + k);
        
        return res;
    }
};