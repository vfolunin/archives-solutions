class Solution {
public:
    int matrixScore(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        for (int y = 0; y < h; y++)
            if (!a[y][0])
                for (int &value : a[y])
                    value ^= 1;
        
        int res = 0;
        
        for (int x = 0; x < w; x++) {
            int ones = 0;
            for (int y = 0; y < h; y++)
                ones += a[y][x];
            
            res += max(ones, h - ones) * (1 << (w - 1 - x));
        }
        
        return res;
    }
};