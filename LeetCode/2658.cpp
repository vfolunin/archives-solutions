class Solution {
    int dfs(vector<vector<int>> &a, int y, int x) {
        int res = a[y][x];
        a[y][x] = 0;

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx])
                res += dfs(a, ty, tx);
        }
        
        return res;
    }
    
public:
    int findMaxFish(vector<vector<int>> &a) {
        int res = 0;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x])
                    res = max(res, dfs(a, y, x));
        return res;
    }
};