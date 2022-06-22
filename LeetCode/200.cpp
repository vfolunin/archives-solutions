class Solution {
    void dfs(vector<vector<char>> &a, int y, int x, vector<vector<int>> &visited) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '1' && !visited[ty][tx])
                dfs(a, ty, tx, visited);
        }
    }
    
public:
    int numIslands(vector<vector<char>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        vector<vector<int>> visited(h, vector<int>(w));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == '1' && !visited[y][x]) {
                    dfs(a, y, x, visited);
                    res++;
                }
            }
        }
        
        return res;
    }
};