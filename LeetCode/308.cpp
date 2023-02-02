struct BIT2D {
    vector<vector<int>> f;

    BIT2D(vector<vector<int>> &a) {
        f.assign(a.size(), vector<int>(a[0].size()));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                add(y, x, a[y][x]);
    }

    int sum(int yr, int xr) {
        int res = 0;
        for (int y = yr; y >= 0; y = (y & (y + 1)) - 1)
            for (int x = xr; x >= 0; x = (x & (x + 1)) - 1)
                res += f[y][x];
        return res;
    }

    int sum(int yl, int xl, int yr, int xr) {
        int res = sum(yr, xr);
        if (yl)
            res -= sum(yl - 1, xr);
        if (xl)
            res -= sum(yr, xl - 1);
        if (yl && xl)
            res += sum(yl - 1, xl - 1);
        return res;
    }

    void add(int cellY, int cellX, int value) {
        for (int y = cellY; y < f.size(); y |= y + 1)
            for (int x = cellX; x < f[0].size(); x |= x + 1)
                f[y][x] += value;
    }
};

class NumMatrix {
    BIT2D bit;

public:
    NumMatrix(vector<vector<int>> &a) : bit(a) {}
    
    void update(int y, int x, int value) {
        value -= bit.sum(y, x, y, x);
        bit.add(y, x, value);
    }
    
    int sumRegion(int yl, int xl, int yr, int xr) {
        return bit.sum(yl, xl, yr, xr);
    }
};