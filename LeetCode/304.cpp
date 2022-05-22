class NumMatrix {
    vector<vector<int>> p;
    
public:
    NumMatrix(vector<vector<int>> &a) {
        p = a;
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
    }
    
    int sumRegion(int yl, int xl, int yr, int xr) {
        int res = p[yr][xr];
        if (yl)
            res -= p[yl - 1][xr];
        if (xl)
            res -= p[yr][xl - 1];
        if (yl && xl)
            res += p[yl - 1][xl - 1];
        return res;
    }
};