class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> ways(h, vector<int>(w));
        ways[0][0] = !a[0][0];
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x])
                    continue;
                if (y)
                    ways[y][x] += ways[y - 1][x];
                if (x)
                    ways[y][x] += ways[y][x - 1];
            }
        }
        
        return ways[h - 1][w - 1];
    }
};