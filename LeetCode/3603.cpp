class Solution {
public:
    long long minCost(int h, int w, vector<vector<int>> &wait) {
        vector<vector<long long>> res(h, vector<long long>(w, 1e18));
        res[0][0] = 1;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y)
                    res[y][x] = min(res[y][x], res[y - 1][x] + (y + 1) * (x + 1) + wait[y][x]);
                if (x)
                    res[y][x] = min(res[y][x], res[y][x - 1] + (y + 1) * (x + 1) + wait[y][x]);
            }
        }

        return res.back().back() - wait.back().back();
    }
};