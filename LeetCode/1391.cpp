class Solution {
    void dfs(vector<vector<int>> &a, int y, int x) {
        int type = a[y][x] - 1;
        a[y][x] = 0;
        
        vector<vector<int>> routes = {
            { 1, 3 }, { 0, 2 }, { 2, 3 }, { 1, 2 }, { 0, 3 }, { 0, 1 }
        };
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int route : routes[type]) {
            int ty = y + dy[route];
            int tx = x + dx[route];
            
            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || !a[ty][tx])
                continue;
            
            for (int tRoute : routes[a[ty][tx] - 1]) {
                int tty = ty + dy[tRoute];
                int ttx = tx + dx[tRoute];
                
                if (tty == y && ttx == x)
                    dfs(a, ty, tx);
            }
        }
    }
    
public:
    bool hasValidPath(vector<vector<int>> &a) {
        dfs(a, 0, 0);
        return !a.back().back();
    }
};