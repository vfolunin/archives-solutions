class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &a, int y, int x, int newColor) {
        int color = a[y][x];
        if (color == newColor)
            return a;
        
        queue<int> q;
        
        a[y][x] = newColor;
        q.push(y);
        q.push(x);
        
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            int x = q.front();
            q.pop();
            
            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };
            
            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx] == color) {
                    a[ty][tx] = newColor;
                    q.push(ty);
                    q.push(tx);
                }
            }
        }
        
        return a;
    }
};