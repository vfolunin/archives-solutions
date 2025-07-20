class Solution {
    int dfs(vector<vector<int>> &a, int y, int x, int mod) {
        int res = a[y][x] % mod;
        a[y][x] = 0;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx])
                res = (res + dfs(a, ty, tx, mod)) % mod;
        }

        return res;
    }

public:
    int countIslands(vector<vector<int>> &a, int mod) {
        int res = 0;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x])
                    res += !dfs(a, y, x, mod);
        return res;
    }
};