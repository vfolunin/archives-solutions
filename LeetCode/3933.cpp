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

    bool isLocalMaximum(vector<vector<int>> &a, vector<vector<vector<int>>> &p, int y, int x) {
        int yl = y - a[y][x];
        int xl = x - a[y][x];
        int yr = y + a[y][x];
        int xr = x + a[y][x];

        int count = getSum(p[a[y][x]], max(yl, 0), max(xl, 0), min(yr, (int)a.size() - 1), min(xr, (int)a[0].size() - 1));

        count -= 0 <= yl && 0 <= xl && a[y][x] < a[yl][xl];
        count -= 0 <= yl && xr < a[0].size() && a[y][x] < a[yl][xr];
        count -= yr < a.size() && 0 <= xl && a[y][x] < a[yr][xl];
        count -= yr < a.size() && xr < a[0].size() && a[y][x] < a[yr][xr];

        return !count;
    }

public:
    int countLocalMaximums(vector<vector<int>> &a) {
        vector p(201, vector(a.size(), vector<int>(a[0].size())));
        for (int value = 0; value < p.size(); value++) {
            for (int y = 0; y < a.size(); y++) {
                for (int x = 0; x < a[0].size(); x++) {
                    p[value][y][x] = a[y][x] > value;
                    if (y)
                        p[value][y][x] += p[value][y - 1][x];
                    if (x)
                        p[value][y][x] += p[value][y][x - 1];
                    if (y && x)
                        p[value][y][x] -= p[value][y - 1][x - 1];
                }
            }
        }

        int res = 0;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res += a[y][x] && isLocalMaximum(a, p, y, x);
        return res;
    }
};