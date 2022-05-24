class Solution {
public:
    int maximalSquare(vector<vector<char>> &a) {
        int h = a.size(), w = a[0].size();
        int maxSize = 0;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                a[y][x] -= '0';
                if (a[y][x] && y && x)
                    a[y][x] += min({ a[y - 1][x - 1], a[y - 1][x], a[y][x - 1] });
                
                maxSize = max(maxSize, a[y][x]);
            }
        }
        
        return maxSize * maxSize;
    }
};