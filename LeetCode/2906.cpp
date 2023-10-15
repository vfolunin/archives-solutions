class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        const long long MOD = 12345;

        vector<vector<long long>> l(h, vector<long long>(w, 1));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (x)
                    l[y][x] = l[y][x - 1] * a[y][x - 1] % MOD;
                else if (y)
                    l[y][x] = l[y - 1][w - 1] * a[y - 1][w - 1] % MOD;
            }
        }

        vector<vector<long long>> r(h, vector<long long>(w, 1));
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                if (x + 1 < w)
                    r[y][x] = r[y][x + 1] * a[y][x + 1] % MOD;
                else if (y + 1 < h)
                    r[y][x] = r[y + 1][0] * a[y + 1][0] % MOD;
            }
        }

        vector<vector<int>> res(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[y][x] = 1LL * l[y][x] * r[y][x] % MOD;
        return res;
    }
};