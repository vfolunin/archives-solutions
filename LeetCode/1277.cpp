class Solution {
public:
    int countSquares(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!a[y][x])
                    continue;

                a[y][x] += min({
                    y && x ? a[y - 1][x - 1] : 0,
                    y ? a[y - 1][x] : 0,
                    x ? a[y][x - 1] : 0
                });
            
                res += a[y][x];
            }
        }
        
        return res;
    }
};