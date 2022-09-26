class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, int time) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !visited[ty][tx] && time <= a[ty][tx])
                dfs(a, ty, tx, visited, time);
        }
    }
    
    bool can(vector<vector<int>> &a, int time) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        
        for (int x = 0; x < a[0].size(); x++)
            if (time <= a[0][x] && !visited[0][x])
                dfs(a, 0, x, visited, time);
        
        for (int x = 0; x < a[0].size(); x++)
            if (visited[a.size() - 1][x])
                return 1;
        
        return 0;
    }
    
public:
    int latestDayToCross(int h, int w, vector<vector<int>> &cells) {
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < cells.size(); i++)
            a[cells[i][0] - 1][cells[i][1] - 1] = i;
        
        int l = 0, r = h * w;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                l = m;
            else
                r = m;
        }
        
        return l;
    }
};