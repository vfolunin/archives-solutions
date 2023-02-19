class Solution {
    void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, int threshold) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] >= threshold && !visited[ty][tx])
                dfs(a, ty, tx, visited, threshold);
        }
    }

    bool can(vector<vector<int>> &a, int threshold) {
        if (a[0][0] < threshold)
            return 0;
        
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        dfs(a, 0, 0, visited, threshold);
        return visited[a.size() - 1][a[0].size() - 1];
    }

public:
    int maximumMinimumPath(vector<vector<int>> &a) {
        int l = 0, r = 1e9 + 1;
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