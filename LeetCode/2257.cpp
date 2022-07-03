class Solution {
public:
    int countUnguarded(int h, int w, vector<vector<int>> &guards, vector<vector<int>>& walls) {
        vector<vector<int>> a(h, vector<int>(w));
        
        for (vector<int> &guard : guards)
            a[guard[0]][guard[1]] = 1;
        for (vector<int> &guard : walls)
            a[guard[0]][guard[1]] = 1;
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        for (vector<int> &guard : guards) {
            for (int d = 0; d < dy.size(); d++) {
                for (int s = 1; 1; s++) {
                    int ty = guard[0] + dy[d] * s;
                    int tx = guard[1] + dx[d] * s;
                    if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] == 1)
                        break;
                    a[ty][tx] = 2;
                }
            }
        }
        
        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += !a[y][x];
        return res;
    }
};