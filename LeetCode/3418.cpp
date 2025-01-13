class Solution {
public:
    int maximumAmount(vector<vector<int>> &a) {
        vector res(a.size(), vector(a[0].size(), vector<int>(3, -1e9)));
        res[0][0] = { a[0][0], max(a[0][0], 0), max(a[0][0], 0) };

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (y) {
                    res[y][x][0] = max(res[y][x][0], res[y - 1][x][0] + a[y][x]);
                    res[y][x][1] = max({ res[y][x][1], res[y - 1][x][1] + a[y][x], res[y - 1][x][0] });
                    res[y][x][2] = max({ res[y][x][2], res[y - 1][x][2] + a[y][x], res[y - 1][x][1] });
                }
                if (x) {
                    res[y][x][0] = max(res[y][x][0], res[y][x - 1][0] + a[y][x]);
                    res[y][x][1] = max({ res[y][x][1], res[y][x - 1][1] + a[y][x], res[y][x - 1][0] });
                    res[y][x][2] = max({ res[y][x][2], res[y][x - 1][2] + a[y][x], res[y][x - 1][1] });
                }
            }
        }

        return *max_element(res.back().back().begin(), res.back().back().end());
    }
};