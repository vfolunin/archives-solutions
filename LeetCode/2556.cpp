class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, vector<vector<pair<int, int>>> &from) {
        visited[y][x] = 1;

        static vector<int> dy = { 1, 0 };
        static vector<int> dx = { 0, 1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] && !visited[ty][tx]) {
                from[ty][tx] = { y, x };
                dfs(a, ty, tx, visited, from);
            }
        }
    }

public:
    bool isPossibleToCutPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> visited(h, vector<int>(w));
        vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, { -1, -1 }));
        dfs(a, 0, 0, visited, from);
        if (!visited[h - 1][w - 1])
            return 1;
        
        auto [y, x] = from[h - 1][w - 1];
        while (y > 0 || x > 0) {
            a[y][x] = 0;
            auto [py, px] = from[y][x];
            y = py;
            x = px;
        }

        visited.assign(h, vector<int>(w));
        dfs(a, 0, 0, visited, from);
        return !visited[h - 1][w - 1];
    }
};