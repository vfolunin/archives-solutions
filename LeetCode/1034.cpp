class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, int color) {
        a[y][x] = -1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == color)
                dfs(a, ty, tx, color);
            else if (ty == -1 || ty == a.size() || tx == -1 || tx == a[0].size() || a[ty][tx] >= 0)
                a[y][x] = -2;   
        }
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &a, int y, int x, int color2) {
        int color1 = a[y][x];
        dfs(a, y, x, color1);
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == -1)
                    a[y][x] = color1;
                else if (a[y][x] == -2)
                    a[y][x] = color2;
            }
        }
        
        return a;
    }
};