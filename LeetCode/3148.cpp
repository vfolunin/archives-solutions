class Solution {
public:
    int maxScore(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> maxCost(h, vector<int>(w, -1e9));
        maxCost[h - 1][w - 1] = 0;
        int res = -1e9;

        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                if (y + 1 < h)
                    maxCost[y][x] = max({ maxCost[y][x], a[y + 1][x] - a[y][x], a[y + 1][x] - a[y][x] + maxCost[y + 1][x] });
                if (x + 1 < w)
                    maxCost[y][x] = max({ maxCost[y][x], a[y][x + 1] - a[y][x], a[y][x + 1] - a[y][x] + maxCost[y][x + 1] });
                if (y + 1 < h || x + 1 < w)
                    res = max(res, maxCost[y][x]);
            }
        }

        return res;
    }
};