class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] && !visited[ty][tx])
                dfs(a, ty, tx, visited);
        }
    }
    
    bool connected(vector<vector<int>> &a) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        int cc = 0;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] && !visited[y][x]) {
                    cc++;
                    dfs(a, y, x, visited);
                }
            }
        }
        
        return cc == 1;
    }
    
public:
    int minDays(vector<vector<int>> &a) {
        if (!connected(a))
            return 0;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x]) {
                    a[y][x] = 0;
                    if (!connected(a))
                        return 1;
                    a[y][x] = 1;
                }
            }
        }
        
        return 2;
    }
};