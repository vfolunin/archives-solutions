class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        
        int y = 0, x = -1, d = 1;
        static int dy[] = {-1, 0, 1, 0};
        static int dx[] = {0, 1, 0, -1};
        
        for (int i = 1; i <= n * n; i++) {
            while (1) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < n && 0 <= tx && tx < n && !a[ty][tx]) {
                    y = ty;
                    x = tx;
                    a[y][x] = i;
                    break;
                } else {
                    d = (d + 1) % 4;
                }
            }                
        }
        
        return a;
    }
};