class Solution {
public:
    void gameOfLife(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> nextA(h, vector<int>(w));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                nextA[y][x] -= a[y][x];
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int ty = y + dy, tx = x + dx;
                        nextA[y][x] += 0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx];
                    }
                }
                
                nextA[y][x] = nextA[y][x] == 3 || a[y][x] && nextA[y][x] == 2;
            }
        }
        
        a.swap(nextA);
    }
};