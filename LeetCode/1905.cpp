class Solution {
    inline static vector<int> dy = { -1, 0, 1, 0 };
    inline static vector<int> dx = { 0, 1, 0, -1 };
    
    void dfs1(vector<vector<int>> &a, int y, int x, int color) {
        a[y][x] = color;
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx] == 1)
                dfs1(a, ty, tx, color);
        }
    }
    
    void dfs2(vector<vector<int>> &a, vector<vector<int>> &b, int y, int x, unordered_set<int> &colors) {
        colors.insert(a[y][x]);        
        b[y][x] = 0;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < b.size() && 0 <= tx && tx < b[ty].size() && b[ty][tx])
                dfs2(a, b, ty, tx, colors);
        }
    }
    
public:
    int countSubIslands(vector<vector<int>> &a, vector<vector<int>> &b) {
        int color = 1;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[y].size(); x++)
                if (a[y][x] == 1)
                    dfs1(a, y, x, ++color);
        
        int res = 0;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[y].size(); x++) {
                if (b[y][x]) {
                    unordered_set<int> colors;
                    dfs2(a, b, y, x, colors);
                    res += colors.size() == 1 && *colors.begin();
                }
            }
        }
        
        return res;
    }
};