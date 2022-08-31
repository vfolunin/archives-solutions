class Solution {
public:
    double knightProbability(int n, int k, int y, int x) {
        vector<vector<double>> p(n, vector<double>(n));
        p[y][x] = 1;
        
        for (int i = 0; i < k; i++) {
            vector<vector<double>> nextP(n, vector<double>(n));
            
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
                    static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
                    
                    for (int d = 0; d < dy.size(); d++) {
                        int ty = y + dy[d];
                        int tx = x + dx[d];
                        
                        if (0 <= ty && ty < n && 0 <= tx && tx < n)
                            nextP[ty][tx] += p[y][x] / dy.size();
                    }
                }
            }
            
            p.swap(nextP);
        }
    
        double res = 0;
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                res += p[y][x];
        return res;
    }
};