class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> res(h, vector<int>(w));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int num = 0, den = 0;
                for (int ty = y - 1; ty <= y + 1; ty++) {
                    for (int tx = x - 1; tx <= x + 1; tx++) {
                        if (0 <= ty && ty < h && 0 <= tx && tx < w) {
                            num += a[ty][tx];
                            den++;
                        }
                    }
                }
                res[y][x] = num / den;
            }
        }
        
        return res;
    }
};