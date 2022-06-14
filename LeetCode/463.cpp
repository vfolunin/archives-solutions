class Solution {
public:
    int islandPerimeter(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x])
                    continue;
                
                res += 4;
                if (y && a[y - 1][x])
                    res -= 2;
                if (x && a[y][x - 1])
                    res -= 2;
            }
        }
        
        return res;
    }
};