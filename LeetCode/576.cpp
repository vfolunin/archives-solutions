class Solution {
public:
    int findPaths(int h, int w, int n, int y, int x) {
        if (!n)
            return 0;
        
        vector<vector<vector<long long>>> ways(n, vector<vector<long long>>(h, vector<long long>(w)));
        ways[0][y][x] = 1;
        
        long long res = 0, MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            for (int y = 0; y < h; y++)
                res = (res + ways[i][y][0] + ways[i][y][w - 1]) % MOD;
            for (int x = 0; x < w; x++)
                res = (res + ways[i][0][x] + ways[i][h - 1][x]) % MOD;
            
            if (i + 1 < n) {
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        static vector<int> dy = { -1, 0, 1, 0 };
                        static vector<int> dx = { 0, 1, 0, -1 };
                        
                        for (int d = 0; d < 4; d++) {
                            int ty = y + dy[d];
                            int tx = x + dx[d];
                            if (0 <= ty && ty < h && 0 <= tx && tx < w)
                                ways[i + 1][ty][tx] = (ways[i + 1][ty][tx] + ways[i][y][x]) % MOD;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};