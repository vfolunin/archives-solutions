class Solution {
public:
    int maxProductPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<long long>> minP(h, vector<long long>(w));
        vector<vector<long long>> maxP(h, vector<long long>(w));
        
        minP[0][0] = maxP[0][0] = a[0][0];
        for (int x = 1; x < w; x++) {
            if (a[0][x] >= 0) {
                minP[0][x] = a[0][x] * minP[0][x - 1];
                maxP[0][x] = a[0][x] * maxP[0][x - 1];
            } else {
                minP[0][x] = a[0][x] * maxP[0][x - 1];
                maxP[0][x] = a[0][x] * minP[0][x - 1];
            }
        }
        
        for (int y = 1; y < h; y++) {
            if (a[y][0] >= 0) {
                minP[y][0] = a[y][0] * minP[y - 1][0];
                maxP[y][0] = a[y][0] * maxP[y - 1][0];
            } else {
                minP[y][0] = a[y][0] * maxP[y - 1][0];
                maxP[y][0] = a[y][0] * minP[y - 1][0];
            }
            
            for (int x = 1; x < w; x++) {
                if (a[y][x] >= 0) {
                    minP[y][x] = a[y][x] * min(minP[y - 1][x], minP[y][x - 1]);
                    maxP[y][x] = a[y][x] * max(maxP[y - 1][x], maxP[y][x - 1]);
                } else {
                    minP[y][x] = a[y][x] * max(maxP[y - 1][x], maxP[y][x - 1]);
                    maxP[y][x] = a[y][x] * min(minP[y - 1][x], minP[y][x - 1]);
                }
            }
        }
        
        const long long MOD = 1e9 + 7;
        return maxP[h - 1][w - 1] >= 0 ? maxP[h - 1][w - 1] % MOD : -1;
    }
};