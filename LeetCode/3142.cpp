class Solution {
public:
    bool satisfiesConditions(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (y + 1 < h && a[y][x] != a[y + 1][x] || x + 1 < w && a[y][x] == a[y][x + 1])
                    return 0;
        return 1;
    }
};