class Solution {
public:
    int minPathSum(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y && x)
                    a[y][x] += min(a[y - 1][x], a[y][x - 1]);
                else if (y)
                    a[y][x] += a[y - 1][x];
                else if (x)
                    a[y][x] += a[y][x - 1];
            }
        }
        return a[h - 1][w - 1];
    }
};