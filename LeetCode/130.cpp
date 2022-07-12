class Solution {
    void dfs(vector<vector<char>> &a, int y, int x) {
        a[y][x] = 'o';
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == 'O')
                dfs(a, ty, tx);
        }
    }
    
public:
    void solve(vector<vector<char>> &a) {
        for (int y = 0; y < a.size(); y++)
            for (int x : { 0, (int)a[0].size() - 1 })
                if (a[y][x] == 'O')
                    dfs(a, y, x);
        
        for (int y : { 0, (int)a.size() - 1 })
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == 'O')
                    dfs(a, y, x);
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 'O')
                    a[y][x] = 'X';
                else if (a[y][x] == 'o')
                    a[y][x] = 'O';
            }
        }
    }
};