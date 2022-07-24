class Solution {
    void dfs(vector<string> &a, int y, int x, int d, vector<vector<vector<int>>> &visited) {
        if (y < 0 || y >= a.size() || x < 0 || x >= a[0].size() || d < 0 || d > 3 || visited[y][x][d])
            return;
        
        visited[y][x][d] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        dfs(a, y + dy[d], x + dx[d], d ^ 2, visited);
        if (a[y][x] != '/')
            dfs(a, y, x, d ^ 1, visited);
        if (a[y][x] != '\\')
            dfs(a, y, x, 3 - d, visited);
    }
    
public:
    int regionsBySlashes(vector<string> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        vector<vector<vector<int>>> visited(h, vector<vector<int>>(w, vector<int>(4)));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                for (int d = 0; d < 4; d++) {
                    if (!visited[y][x][d]) {
                        res++;
                        dfs(a, y, x, d, visited);
                    }
                }
            }
        }
        
        return res;
    }
};