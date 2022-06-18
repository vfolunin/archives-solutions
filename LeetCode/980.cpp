class Solution {
    int rec(vector<vector<int>> &a, int y, int x, int length) {
        if (length == 1)
            return a[y][x] == 2;
        
        int prevValue = a[y][x];
        a[y][x] = -1;
        int res = 0;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != -1)
                res += rec(a, ty, tx, length - 1);
        }
        
        a[y][x] = prevValue;
        return res;
    }
    
public:
    int uniquePathsIII(vector<vector<int>> &a) {
        int sy, sx, length = 0;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 1) {
                    sy = y;
                    sx = x;
                }
                length += a[y][x] != -1;
            }
        }
        
        return rec(a, sy, sx, length);
    }
};