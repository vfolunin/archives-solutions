class Solution {
public:
    int numSubmat(vector<vector<int>> &p) {
        int h = p.size(), w = p[0].size(), res = 0;
        
        for (int y = 1; y < h; y++)
            for (int x = 0; x < w; x++)
                if (p[y][x])
                    p[y][x] += p[y - 1][x];
        
        for (int y1 = 0; y1 < h; y1++) {
            for (int y2 = y1; y2 < h; y2++) {
                int row = 0;
                for (int x = 0; x < w; x++) {
                    if (p[y2][x] >= y2 - y1 + 1)
                        row++;
                    else
                        row = 0;
                    res += row;
                }
            }
        }
        
        return res;
    }
};