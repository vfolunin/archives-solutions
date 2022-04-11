class Solution {
    int dfs(vector<vector<int>> &a, int y, int x) {
        a[y][x] = 0;
        int area = 1;
        
        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx])
                area += dfs(a, ty, tx);
        }
        
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>> &a) {
        int maxArea = 0;
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[y].size(); x++)
                if (a[y][x])
                    maxArea = max(maxArea, dfs(a, y, x));
        
        return maxArea;
    }
};