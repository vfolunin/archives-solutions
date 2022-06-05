class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &a) {
        vector<int> dy = { -1, 0 , 1, 0 };
        vector<int> dx = { 0 , 1, 0, -1 };
        int h = a.size(), w = a[0].size(), y = 0, x = 0, d = 1;
        
        vector<int> res(h * w);
        for (int i = 0; i < res.size(); i++) {
            res[i] = a[y][x];
            a[y][x] = 1e9;
            
            if (i + 1 == res.size())
                break;
            
            while (1) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != 1e9) {
                    y = ty;
                    x = tx;
                    break;
                }
                d = (d + 1) % 4;
            }
        }
        
        return res;
    }
};