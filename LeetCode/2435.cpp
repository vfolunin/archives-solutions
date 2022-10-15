class Solution {
public:
    int numberOfPaths(vector<vector<int>> &a, int d) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<long long>>> res(h, vector<vector<long long>>(w, vector<long long>(d)));
        res[0][0][a[0][0] % d] = 1;
        
        const long long MOD = 1e9 + 7;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                for (int r = 0; r < d; r++) {
                    if (y + 1 < h) {
                        int tr = (r + a[y + 1][x]) % d;
                        res[y + 1][x][tr] = (res[y + 1][x][tr] + res[y][x][r]) % MOD;
                    }
                    if (x + 1 < w) {
                        int tr = (r + a[y][x + 1]) % d;
                        res[y][x + 1][tr] = (res[y][x + 1][tr] + res[y][x][r]) % MOD;
                    }
                }
            }
        }
        
        return res[h - 1][w - 1][0];
    }
};