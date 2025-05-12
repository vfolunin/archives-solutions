struct PrefixSum2D {
    vector<vector<long long>> p;

    PrefixSum2D(vector<vector<int>> &a) {
        p.assign(a.size(), vector<long long>(a[0].size()));
        for (int y = 0; y < p.size(); y++) {
            for (int x = 0; x < p[0].size(); x++) {
                p[y][x] = a[y][x];
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
    }

    long long getSum(int yl, int xl, int yr, int xr) {
        long long res = p[yr][xr];
        if (yl)
            res -= p[yl - 1][xr];
        if (xl)
            res -= p[yr][xl - 1];
        if (yl && xl)
            res += p[yl - 1][xl - 1];
        return res;
    }
};

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>> &a) {
        PrefixSum2D p(a);

        for (int y = 1; y < a.size(); y++)
            if (p.getSum(0, 0, y - 1, a[0].size() - 1) == p.getSum(y, 0, a.size() - 1, a[0].size() - 1))
                return 1;

        for (int x = 1; x < a[0].size(); x++)
            if (p.getSum(0, 0, a.size() - 1, x - 1) == p.getSum(0, x, a.size() - 1, a[0].size() - 1))
                return 1;
        
        return 0;
    }
};