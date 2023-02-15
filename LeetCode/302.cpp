class Solution {
    void dfs(vector<vector<char>> &a, int y, int x, int &minY, int &minX, int &maxY, int &maxX) {
        a[y][x] = '0';

        minY = min(minY, y);
        minX = min(minX, x);
        maxY = max(maxY, y);
        maxX = max(maxX, x);
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '1')
                dfs(a, ty, tx, minY, minX, maxY, maxX);
        }
    }

public:
    int minArea(vector<vector<char>> &a, int y, int x) {
        int minY = a.size(), minX = a[0].size(), maxY = 0, maxX = 0;
        dfs(a, y, x, minY, minX, maxY, maxX);
        return (maxY - minY + 1) * (maxX - minX + 1);
    }
};