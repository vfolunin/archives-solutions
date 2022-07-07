class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int h, int w, int y, int x) {
        vector<vector<int>> res = { { y, x } };
        
        vector<int> dy = { 1, 0, -1, 0 };
        vector<int> dx = { 0, -1, 0, 1 };
        
        for (int step = 2; res.size() < h * w; step += 2) {
            for (int d = 0; d < dy.size(); d++) {
                for (int s = 0; s < step; s++) {
                    if (!d && !s) {
                        x++;
                    } else {
                        y += dy[d];
                        x += dx[d];
                    }
                    
                    if (0 <= y && y < h && 0 <= x && x < w)
                        res.push_back({ y, x });
                }
            }
        }
        
        return res;
    }
};