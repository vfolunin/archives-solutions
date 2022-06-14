class Solution {
public:
    int numRookCaptures(vector<vector<char>> &a) {
        int ry, rx;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (a[y][x] == 'R') {
                    ry = y;
                    rx = x;
                }
            }
        }
        
        int res = 0;
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        for (int d = 0; d < 4; d++) {
            for (int step = 1; step < 8; step++) {
                int ty = ry + dy[d] * step;
                int tx = rx + dx[d] * step;
                if (ty < 0 || ty > 7 || tx < 0 || tx > 7 || a[ty][tx] == 'B')
                    break;
                if (a[ty][tx] == 'p') {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};